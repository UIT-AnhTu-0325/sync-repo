package main

import "math"

func minCapability(nums []int, k int) int {
	return calc(nums, k, 0, 0)
}

func calc(nums []int, k int, crrIdx int, crrMax int) int {
	if k == 0 {
		return crrMax
	}
	if crrIdx >= len(nums) {
		return math.MaxInt
	}

	pick := calc(nums, k-1, crrIdx+2, max(crrMax, nums[crrIdx]))
	notPick := calc(nums, k, crrIdx+1, crrMax)

	res := min(pick, notPick)

	return res
}

func main() {
	_ = minCapability
}
