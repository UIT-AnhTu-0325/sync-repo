package main

func main() {
	_ = isZeroArray
}

func isZeroArray(nums []int, queries [][]int) bool {
	mem := make([]int, len(nums)+1)
	for i := range queries {
		mem[queries[i][0]]--
		mem[queries[i][1]+1]++
	}
	crrMinus := 0
	for i := range queries {
		crrMinus += mem[i]
		if crrMinus+nums[i] > 0 {
			return false
		}
	}
	return true
}
