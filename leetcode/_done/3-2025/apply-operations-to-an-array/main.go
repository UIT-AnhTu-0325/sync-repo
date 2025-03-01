package main

func applyOperations(nums []int) []int {
	if len(nums) == 1 || len(nums) == 0 {
		return nums
	}
	for i := 0; i < len(nums)-1; i++ {
		if nums[i] == nums[i+1] {
			nums[i] *= 2
			nums[i+1] = 0
		}
	}
	res := make([]int, 0)
	cZero := 0
	for i := range nums {
		if nums[i] == 0 {
			cZero++
		} else {
			res = append(res, nums[i])
		}
	}
	for i := 0; i < cZero; i++ {
		res = append(res, 0)
	}
	return res
}
func main() {
	_ = applyOperations
}
