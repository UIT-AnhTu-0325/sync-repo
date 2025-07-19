package main

func main() {
	findDuplicate([]int{1, 3, 4, 2, 2})
}

func findDuplicate(nums []int) int {
	left := 1
	right := len(nums) - 1
	for left < right {
		cnt := 0
		mid := (left + right) / 2
		for i := range nums {
			if nums[i] <= mid {
				cnt++
			}
		}
		if cnt > mid {
			right = mid
		} else {
			left = mid + 1
		}
	}
	return left
}
