package main

import (
	"example/web-service-gin/routes"
)

func main() {
	router := routes.GetRoute()
	router.Run("localhost:8080")
}
