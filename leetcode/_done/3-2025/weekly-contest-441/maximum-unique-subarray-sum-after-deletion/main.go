package main

import "math"

func maxSum(nums []int) int {
	sum := 0
	max := math.MinInt32
	pickOne := false
	selected := make(map[int]int)
	for idx := range nums {
		if nums[idx] > 0 {
			pickOne = true
			_, exists := selected[nums[idx]]
			if !exists {
				selected[nums[idx]] = 1
				sum += nums[idx]
			}
		}
		max = _max(max, nums[idx])
	}

	if pickOne {
		return sum
	} else {
		return max
	}
}

func _max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	_ = maxSum
}
