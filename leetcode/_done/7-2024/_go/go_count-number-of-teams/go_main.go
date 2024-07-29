package main

import "fmt"

func numTeams(rating []int) int {
	n := len(rating)
	build1 := make([]int, n)
	build2 := make([]int, n)

	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			if rating[j] > rating[i] {
				build1[i]++
			} else {
				build2[i]++
			}
		}
	}

	res := 0

	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			if rating[j] > rating[i] {
				res += build1[j]
			} else {
				res += build2[j]
			}
		}
	}

	return res
}

func main() {
	numTeams([]int{})
	fmt.Println("Hello, 世界")
}
