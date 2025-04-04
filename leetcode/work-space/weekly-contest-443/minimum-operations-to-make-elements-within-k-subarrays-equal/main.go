package main

import (
	"math"
	"slices"
	"sort"
)

func minOperations(nums []int, x int, k int) int64 {
	n := len(nums)
	return calc(nums, x, k, 0, n-1)
}

// Function to find the minimum steps to make all elements equal
func minStepsToEqual(arr []int) int64 {
	// Sort the array
	sort.Ints(arr)

	// Find possible medians
	n := len(arr)
	median1 := arr[n/2]     // Lower middle
	median2 := arr[(n-1)/2] // Higher middle (only matters for even-length)

	// Compute steps for both medians and take the minimum
	return min(totalSteps(arr, median1), totalSteps(arr, median2))
}

// Helper function to calculate steps for a given median
func totalSteps(arr []int, median int) int64 {
	steps := int64(0)
	for _, num := range arr {
		steps += _abs(int64(num - median))
	}
	return steps
}

func calc(nums []int, x int, k int, start int, end int) int64 {
	if k == 0 {
		return 0
	}
	if end+1-start == x {
		return minStepsToEqual(nums[start : end+1])
	}
	n := len(nums)
	minAdjust := int64(math.MaxInt64)
	for i := start; i < n-x*(k-1); i++ {
		crrAdjust := calc(nums, x, k, i, i+x-1)
		minAdjust = min(calc(nums, x, k-1, i+x, n-1)+crrAdjust, minAdjust)
	}
	return minAdjust
}

func _min(nums ...int64) int64 {
	return slices.Min(nums)
}

func _abs(n int64) int64 {
	if n < 0 {
		return -n
	}
	return n
}

func main() {
	_ = minOperations([]int{-17, 17, -11}, 3, 1)
}
