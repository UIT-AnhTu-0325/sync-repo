package main

func pivotArrayO_n(nums []int, pivot int) []int {
	res := make([]int, 0)
	for i := range nums {
		if nums[i] < pivot {
			res = append(res, nums[i])
		}
	}
	for i := range nums {
		if nums[i] == pivot {
			res = append(res, nums[i])
		}
	}
	for i := range nums {
		if nums[i] > pivot {
			res = append(res, nums[i])
		}
	}
	return res
}

func pivotArray(nums []int, pivot int) []int {

	return nums
}

func main() {
	_ = pivotArrayO_n
	_ = pivotArray
}
