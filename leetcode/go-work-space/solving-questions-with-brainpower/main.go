package main

import "slices"

func mostPoints(questions [][]int) int64 {
	n := len(questions) - 1
	mem := make([]int64, n+1)
	mem[n] = int64(questions[n][0])

	for i := n - 1; i >= 0; i-- {
		nextAval := i + questions[i][1] + 1
		if nextAval <= n {
			mem[i] = _max(mem[i+1], int64(questions[i][0])+mem[nextAval])
		} else {
			mem[i] = _max(mem[i+1], int64(questions[i][0]))
		}
	}
	return mem[0]
}

func _max(nums ...int64) int64 {
	return slices.Max(nums)
}

func main() {
	_ = mostPoints([][]int{{3, 2}, {4, 3}, {4, 4}, {2, 5}})
}
