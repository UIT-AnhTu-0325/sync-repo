package main

func main() {
	_ = findMin([]int{3, 4, 5, 1, 2})
}

func findMin(nums []int) int {
	left := 0
	right := len(nums) - 1
	for left < right {
		mid := left + (right-left)/2
		if nums[mid] > nums[right] {
			left = mid + 1
		} else if nums[mid] < nums[left] {
			right = mid
		} else if nums[mid] < nums[right] {
			right = mid
		} else {
			left = mid
		}
	}
	return nums[right]
}
