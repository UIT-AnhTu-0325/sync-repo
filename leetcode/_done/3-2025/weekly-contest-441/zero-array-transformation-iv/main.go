package main

import "math"

func minZeroArray(nums []int, queries [][]int) int {
	maxPick := math.MinInt
	for idx := range nums {
		mem := make(map[int]map[int]int)
		maxPick = _max(minOfOne(nums[idx], idx, queries, 0, mem), maxPick)
	}
	if maxPick > len(queries) {
		return -1
	} else {
		return maxPick
	}
}

func minOfOne(crrValue int, crrIdx int, queries [][]int, crrQIdx int, mem map[int]map[int]int) int {
	if val, exists := mem[crrValue]; exists {
		if val2, exists2 := val[crrQIdx]; exists2 {
			return val2
		}
	} else {
		mem[crrValue] = make(map[int]int)
	}
	if crrValue == 0 {
		return crrQIdx
	}
	if crrQIdx >= len(queries) {
		return len(queries) + 1
	}

	crrQuery := queries[crrQIdx]
	if crrIdx >= crrQuery[0] && crrIdx <= crrQuery[1] && crrValue >= crrQuery[2] {
		minIfPick := minOfOne(crrValue-crrQuery[2], crrIdx, queries, crrQIdx+1, mem)
		minNotPick := minOfOne(crrValue, crrIdx, queries, crrQIdx+1, mem)
		res := _min(minIfPick, minNotPick)
		mem[crrValue][crrQIdx+1] = minNotPick
		mem[crrValue][crrQIdx] = res
		return res
	} else {
		res := minOfOne(crrValue, crrIdx, queries, crrQIdx+1, mem)
		mem[crrValue][crrQIdx] = res
		mem[crrValue][crrQIdx+1] = res
		return res
	}
}

func _min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func _max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	nums := []int{2, 0, 2}

	queries := [][]int{
		{0, 2, 1},
		{0, 2, 1},
		{1, 1, 3},
	}
	_ = minZeroArray(nums, queries)
}
