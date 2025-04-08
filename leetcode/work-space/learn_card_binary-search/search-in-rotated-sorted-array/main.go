package main

func main() {
	_ = search([]int{5, 1, 2, 3, 4}, 1)
}

func search(nums []int, target int) int {
	left := 0
	right := len(nums) - 1
	for left <= right {
		mid := (left + right) / 2
		if nums[mid] == target {
			return mid
		}
		if nums[mid] >= nums[left] && nums[mid] <= nums[right] {
			if nums[mid] > target {
				right = mid - 1
			} else {
				left = mid + 1
			}
		} else if nums[mid] > nums[right] {
			if nums[right] >= target {
				left = mid + 1
			} else if nums[mid] > target {
				right = mid - 1
			} else {
				left = mid + 1
			}
		} else if nums[mid] < nums[left] {
			if nums[left] <= target {
				right = mid - 1
			} else if nums[mid] < target {
				left = mid + 1
			} else {
				right = mid - 1
			}
		}
	}
	return -1
}
