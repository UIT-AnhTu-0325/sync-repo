package main

import "slices"

func maximumTripletValue(nums []int) int64 {
	n := len(nums)
	mem := make([]int, 0)
	mem = append(mem, nums[n-1])
	for i := n - 2; i >= 0; i-- {
		mem = append(mem, max(nums[i], mem[len(mem)-1]))
	}
	slices.Reverse(mem)

	res := int64(0)
	for i := 0; i < n-2; i++ {
		for j := i + 1; j < n-1; j++ {
			res = max(int64(nums[i]-nums[j])*int64(mem[j+1]), res)
		}
	}
	return res
}

func main() {
	_ = maximumTripletValue([]int{12, 6, 1, 2, 7})
}
