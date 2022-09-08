package main

/*
	1. gorm 连接数据库
	2. 配置 logger
	3. auto migrate
	4. gorm的模型的CRUD
	5. Updates 默认只设置非空的字段，需要通过NullString解决不能更新零值的问题
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

type Product struct {
	gorm.Model
	Code  sql.NullString
	Price uint
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
	if err := db.AutoMigrate(&Product{}); err != nil {
		panic(err)
	}

	// Create
	db.Create(&Product{Code: sql.NullString{String: "D42", Valid: true}, Price: 100})

	// Read
	var product Product
	db.First(&product, 1)                 // 根据整型主键查找
	db.First(&product, "code = ?", "D42") // 查找 code 字段值为 D42 的记录

	// Update - 将 product 的 price 更新为 200
	db.Model(&product).Update("Price", 200)
	// Update - 更新多个字段
	db.Model(&product).Updates(Product{Price: 200, Code: sql.NullString{String: "", Valid: true}})
	db.Model(&product).Updates(map[string]interface{}{"Price": 200, "Code": "F42"})

	// Delete - 删除 product，设置删除时间，逻辑删除
	db.Delete(&product, 1)
}
