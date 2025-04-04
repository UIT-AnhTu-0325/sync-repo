package main

import "slices"

func maximumTripletValue(nums []int) int64 {
	n := len(nums)
	memSuf := make([]int, 0)
	memSuf = append(memSuf, nums[n-1])
	for i := n - 2; i >= 0; i-- {
		memSuf = append(memSuf, max(nums[i], memSuf[len(memSuf)-1]))
	}
	slices.Reverse(memSuf)

	memPre := make([]int, 0)
	memPre = append(memPre, nums[0])
	for i := 0; i < n-1; i++ {
		memPre = append(memPre, max(memPre[i], nums[i+1]))
	}

	res := int64(0)
	for i := 1; i < n-1; i++ {
		res = max(res, int64(memPre[i-1]-nums[i])*int64(memSuf[i+1]))
	}
	return res
}
