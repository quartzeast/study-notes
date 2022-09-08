package main

/*
	1. 基本查询
*/

import (
	"database/sql"
	"errors"
	"log"
	"os"
	"time"

	"gorm.io/driver/mysql"
	"gorm.io/gorm"
	"gorm.io/gorm/logger"
)

type User struct {
	ID           uint
	MyName       string `gorm:"column:name"`
	Email        *string
	Age          uint8
	Birthday     *time.Time
	MemberNumber sql.NullString
	ActivatedAt  sql.NullTime
	CreatedAt    time.Time
	UpdatedAt    time.Time
}

func main() {
	// 参考 https://github.com/go-sql-driver/mysql#dsn-data-source-name 获取详情
	dsn := "root:marx123@tcp(192.168.1.8:3306)/gorm_test?charset=utf8mb4&parseTime=True&loc=Local"

	// 设置全局的 logger，这个 logger 在我们执行 sql 是会打印每一行 sql
	newLogger := logger.New(
		log.New(os.Stdout, "\r\n", log.LstdFlags), // io writer（日志输出的目标，前缀和日志包含的内容——译者注）
		logger.Config{
			SlowThreshold:             time.Second, // 慢 SQL 阈值
			LogLevel:                  logger.Info, // 日志级别
			IgnoreRecordNotFoundError: true,        // 忽略ErrRecordNotFound（记录未找到）错误
			Colorful:                  true,        // 使用彩色打印
		},
	)

	db, err := gorm.Open(mysql.Open(dsn), &gorm.Config{
		Logger: newLogger,
	})
	if err != nil {
		panic(err)
	}

	// 定一个表结构（模型），将模型直接映射为数据库中的表——migration
	if err := db.AutoMigrate(&User{}); err != nil {
		panic(err)
	}

	// 通过 First 查询单个数据，获取第一条记录（主键升序）
	var user User
	// result := db.First(&user)
	// errors.Is(result.Error, gorm.ErrRecordNotFound)
	// log.Println(user.ID)

	// 通过主键查询
	// 不能给 user 赋值
	result := db.First(&user, 10)
	if errors.Is(result.Error, gorm.ErrRecordNotFound) {
		log.Println("未找到")
	} else {
		log.Println(user.ID)
	}

	var users []User
	// 检索全部对象
	result = db.Find(&users)
	log.Println("总共记录：", result.RowsAffected)

	for _, user := range users {
		log.Println(user.ID)
	}

	db.Where("name = ?", "jinzhu").First(&user)
	db.Where(&User{MyName: "jinzhu"}).First(&user)
}
