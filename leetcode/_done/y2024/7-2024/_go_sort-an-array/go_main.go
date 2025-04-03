package main

import "fmt"

func merge(nums []int, start int, end int) []int {
	if start >= end {
		return nums
	}

	middle := (start + end) / 2

	nums = merge(nums, start, middle)
	nums = merge(nums, middle+1, end)

	merged := []int{}
	i, j := start, middle+1

	for i <= middle && j <= end {
		if nums[i] > nums[j] {
			merged = append(merged, nums[j])
			j++
		} else {
			merged = append(merged, nums[i])
			i++
		}
	}

	for i <= middle {
		merged = append(merged, nums[i])
		i++
	}

	for j <= end {
		merged = append(merged, nums[j])
		j++
	}

	mIdx := 0
	for i := start; i <= end; i++ {
		nums[i] = merged[mIdx]
		mIdx++
	}

	return nums
}

func sortArray(nums []int) []int {
	result := merge(nums, 0, len(nums)-1)
	return result
}

func main() {
	sortArray([]int{})
	fmt.Println("Hello, 世界")
}
