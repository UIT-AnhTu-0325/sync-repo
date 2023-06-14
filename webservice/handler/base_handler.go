package handler

import (
	"example/webservice-gin/model"
	"io"
	"net/http"
	"os"

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

	g.GET("/", func(ctx *gin.Context) {
		ctx.JSON(http.StatusOK, gin.H{
			"Hello": "It's my world!",
		})
	})

	g.GET("/home", func(ctx *gin.Context) {
		f, err := os.Open("public/html/home.html")
		if err != nil {
			ctx.JSON(http.StatusInternalServerError, gin.H{
				"Error": err,
			})
		}
		defer f.Close()
		ctx.Header(ctx.ContentType(), "text/css")
		io.Copy(ctx.Writer, f)
	})

	g.GET("/me", h.Me)
	g.POST("/signup", h.Signup)
}
