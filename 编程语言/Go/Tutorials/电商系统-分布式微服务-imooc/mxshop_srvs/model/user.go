package model

import (
	"time"

	"gorm.io/gorm"
)

/*
	1. 密文保存密码
	2. 密文不可反解
		对称加密
		非对称加密
		✅md5盐值加密 信息摘要算法
		密码如果不可反解，用户如何找回密码？发送链接，让用户修改密码
		md5 加密涉及到彩虹表的暴力破解问题，要采用盐值加密的方式

		go-password-encoder
		密码保存：算法/盐值/生成的摘要密码
*/

type BaseModel struct {
	ID        int32     `gorm:"primaryKey"`
	CreateAt  time.Time `gorm:"column:add_time"`
	UpdateAt  time.Time `gorm:"column:update_time"`
	DeletedAt gorm.DeletedAt
	IsDeleted bool `gorm:"column:is_deleted"`
}

type User struct {
	BaseModel
	Mobile   string     `gorm:"index:idx_mobile;unique;type:varchar(11);not null"`
	Password string     `gorm:"type:varchar(100);not null"`
	Nickname string     `gorm:"type:varchar(20)"`
	Birthday *time.Time `gorm:"type:datetime"`
	Gender   string     `gorm:"column:gender;default:male;type:varchar(6)"`
	Role     int        `gorm:"column:role;default:1;type:int comment '1 表示普通用户, 2 表示管理员'"`
}
