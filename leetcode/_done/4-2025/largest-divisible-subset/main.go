package main

import (
	"slices"
	"sort"
)

func main() {
	_ = largestDivisibleSubset([]int{4, 8, 10, 240})
}

func largestDivisibleSubset(nums []int) []int {
	rawNum := make([]int, 0)
	for i := range nums {
		rawNum = append(rawNum, nums[i])
	}
	sort.Ints(nums)

	mem := make([][]int, len(nums))
	for i := range mem {
		mem[i] = make([]int, 0)
	}
	finalMax := make([]int, 0)
	for i := 0; i < len(nums); i++ {
		crrMax := []int{nums[i]}
		for j := i - 1; j >= 0; j-- {
			if nums[i]%nums[j] == 0 {
				if len(crrMax) < len(mem[j])+1 {
					crrMax = deepCopy(mem[j])
					crrMax = append(crrMax, nums[i])
				}
			}
		}
		if len(crrMax) > len(finalMax) {
			finalMax = crrMax
		}
		mem[i] = crrMax
	}
	res := make([]int, 0)
	for i := range rawNum {
		if slices.Contains(finalMax, rawNum[i]) {
			res = append(res, rawNum[i])
		}
	}
	return res
}

func deepCopy(original []int) []int {
	copy := make([]int, len(original))
	for i, person := range original {
		copy[i] = person
	}
	return copy
}
