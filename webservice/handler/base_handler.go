package handler

import (
	"example/webservice-gin/model"
	"net/http"

	"github.com/gin-gonic/gin"
)

type Handler struct {
	UserService  model.UserService
	TokenService model.TokenService
}

type Config struct {
	R            *gin.Engine
	UserService  model.UserService
	TokenService model.TokenService
	BaseURL      string
}

func NewHandler(c *Config) {
	g := c.R.Group(c.BaseURL)
	h := &Handler{
		UserService:  c.UserService,
		TokenService: c.TokenService,
	}
	//Test func
	g.GET("/", func(ctx *gin.Context) {
		ctx.JSON(http.StatusOK, gin.H{
			"Hello": "It's my world!",
		})
	})

	g.GET("/me", h.Me)
	g.POST("/signup", h.Signup)
}
