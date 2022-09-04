package main

import "github.com/gin-gonic/gin"

func pong(c *gin.Context) {
	// panic("panic")
	c.JSON(200, gin.H{
		"message": "pong",
	})
}

func main() {
	r := gin.Default()
	r.GET("/ping", pong)
	r.Run() // listen and serve on 0.0.0.0:8080
}
