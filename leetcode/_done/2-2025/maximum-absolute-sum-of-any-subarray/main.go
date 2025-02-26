package main

import (
	"fmt"
	"math"
)

func _max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func _min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func _abs(n int) int {
	if n < 0 {
		return -n
	}
	return n
}

func maxAbsoluteSum(nums []int) int {
	prefixSum := 0
	minPrefixSum := math.MaxInt32
	maxPrefixSum := math.MinInt32
	res := 0
	for i := 0; i < len(nums); i++ {
		prefixSum += nums[i]
		minPrefixSum = _min(minPrefixSum, prefixSum)
		maxPrefixSum = _max(maxPrefixSum, prefixSum)
		if prefixSum > 0 {
			res = _max(res, _max(prefixSum, _abs(prefixSum-minPrefixSum)))
		} else {
			res = _max(res, _max(_abs(prefixSum), _abs(prefixSum-maxPrefixSum)))
		}
	}
	return res
}

func main() {
	_ = maxAbsoluteSum([]int{1, -3, 2, 3, -4})
	fmt.Println("Hello")
}
