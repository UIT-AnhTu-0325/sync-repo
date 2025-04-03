package main

func findPeakElement(nums []int) int {
	return solve(nums, 0, len(nums)-1)
}

func solve(nums []int, left int, right int) int {
	if left > right {
		return -1
	}

	crr := (left + right) / 2

	if (crr == 0 || nums[crr-1] < nums[crr]) && (crr == len(nums)-1 || nums[crr+1] < nums[crr]) {
		return crr
	}

	resLeft := solve(nums, left, crr-1)

	if resLeft != -1 {
		return resLeft
	}

	resRight := solve(nums, crr+1, right)

	if resRight != -1 {
		return resRight
	}

	return -1
}

func main() {
	_ = findPeakElement([]int{1, 2, 3, 1})
}
