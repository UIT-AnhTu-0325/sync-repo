package main

import "math"

func main() {
	minTimeToReach([][]int{{0, 0, 0}, {0, 0, 0}})
}

func minTimeToReach(moveTime [][]int) int {
	m := len(moveTime)
	n := len(moveTime[0])
	minTime := make([][]int, m)
	traveled := make([][]bool, m)

	for i := range minTime {
		minTime[i] = make([]int, n)
		traveled[i] = make([]bool, n)
		for j := range minTime[i] {
			minTime[i][j] = math.MaxInt
		}
	}
	moveTime[0][0] = -1
	calc(0, 0, 0, moveTime, minTime, m, n)
	return minTime[m-1][n-1]
}

var direction = [][]int{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}

func calc(i int, j int, crrTime int, moveTime [][]int, minTime [][]int, m int, n int) {
	if i < 0 || i >= m || j < 0 || j >= n {
		return
	}
	minCrrTime := max(crrTime, moveTime[i][j]+1)

	if minCrrTime >= minTime[i][j] {
		return
	}

	minTime[i][j] = minCrrTime

	for idx := range direction {
		calc(i+direction[idx][0], j+direction[idx][1], minTime[i][j]+1, moveTime, minTime, m, n)
	}
}
