package main

func main() {
	_ = findPeakElement([]int{1, 2, 3, 1})
}

func findPeakElement(nums []int) int {
	left := 0
	right := len(nums) - 1
	for left < right {
		mid := left + (right-left)/2
		if nums[mid] > nums[mid+1] {
			right = mid
		} else {
			left = mid + 1
		}
	}
	return left
}
