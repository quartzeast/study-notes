package main

/*
	1. 通过 create 方法插入记录
*/

import (
	"database/sql"
	"log"
	"os"
	"time"

	"gorm.io/driver/mysql"
	"gorm.io/gorm"
	"gorm.io/gorm/logger"
)

type User struct {
	ID           uint
	Name         string
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

	user := User{
		Name: "dong",
	}
	result := db.Create(&user)
	log.Println(user.ID, result.Error, result.RowsAffected)
	db.Model(&User{ID: 1}).Update("name", "")
	// Updates 语句不会更新零值，但是 Update 语句会更新
	// db.Model(&User{ID: 1}).Updates(User{Name: ""})
	// 解决仅更新非零值字段的方法有两种
	// 1. 将 string 设置为 *string
	// 2. 使用 sql.NULLxxx
	empty := ""
	db.Model(&User{ID: 1}).Updates(User{Email: &empty})
}
