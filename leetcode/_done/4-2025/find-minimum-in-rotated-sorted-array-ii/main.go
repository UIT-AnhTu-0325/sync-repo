package main

import "math"

func main() {
	_ = findMin([]int{3, 3, 1, 3})
}

func findMin(nums []int) int {
	left := 0
	right := len(nums) - 1
	return calc(nums, left, right)
}

func calc(nums []int, left int, right int) int {
	if left > right {
		return math.MaxInt
	}
	if left == right {
		return nums[left]
	}
	mid := left + (right-left)/2
	if nums[mid] > nums[right] {
		return calc(nums, mid+1, right)
	}
	if nums[mid] < nums[right] {
		return calc(nums, left, mid)
	}
	minLeft := calc(nums, left, mid)
	minRight := calc(nums, mid+1, right)
	return min(minLeft, minRight)
}
