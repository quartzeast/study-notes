package main

import (
	"crypto/md5"
	"encoding/hex"
	"io"
	"log"
	"mxshop_srvs/model"
	"os"
	"time"

	"gorm.io/driver/mysql"
	"gorm.io/gorm"
	"gorm.io/gorm/logger"
	"gorm.io/gorm/schema"
)

func main() {
	// 参考 https://github.com/go-sql-driver/mysql#dsn-data-source-name 获取详情
	dsn := "root:marx123@tcp(192.168.1.8:3306)/mxshop_user_srv?charset=utf8mb4&parseTime=True&loc=Local"

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
		NamingStrategy: schema.NamingStrategy{
			SingularTable: true,
		},
		Logger: newLogger,
	})
	if err != nil {
		log.Fatalln(err)
	}

	// 定一个表结构（模型），将模型直接映射为数据库中的表——migration
	if err := db.AutoMigrate(&model.User{}); err != nil {
		log.Fatalln(err)
	}
}

func GenerateMd5Hash(code string) string {
	md5 := md5.New()
	io.WriteString(md5, code)
	return hex.EncodeToString(md5.Sum(nil))
}
