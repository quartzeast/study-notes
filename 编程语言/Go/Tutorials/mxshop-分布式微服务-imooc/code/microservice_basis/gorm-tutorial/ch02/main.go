package main

/*
	1. 表结构定义细节
*/

import (
	"log"
	"os"
	"time"

	"gorm.io/driver/mysql"
	"gorm.io/gorm"
	"gorm.io/gorm/logger"
)

type User struct {
	UserID uint   `gorm:"primaryKey"`
	Name   string `gorm:"column:user_name;type:varchar(50);index:idx_user_name;unique;default:'dongdong'"`
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

	db.Create(&User{})
}
