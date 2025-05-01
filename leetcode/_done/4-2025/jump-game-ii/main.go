package main

import "math"

func main() {

}

func jump(nums []int) int {
	return calc(nums, 0, make(map[int]int))
}

func calc(nums []int, crrIdx int, mem map[int]int) int {
	if crrIdx == len(nums)-1 {
		return 0
	}
	if val, ex := mem[crrIdx]; ex {
		return val
	}
	minStep := math.MaxInt - 1
	for i := 1; i <= nums[crrIdx]; i++ {
		if i+crrIdx >= len(nums) {
			break
		}
		minStep = min(minStep, calc(nums, i+crrIdx, mem))
	}
	mem[crrIdx] = minStep + 1
	return minStep + 1
}
