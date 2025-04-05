package main

func main() {
	_ = searchRange([]int{1, 4}, 4)
}

func searchRange(nums []int, target int) []int {
	left := 0
	right := len(nums) - 1
	mid := 0
	for left <= right {
		mid = left + (right-left)/2
		if nums[mid] > target {
			right = mid - 1
		} else if nums[mid] < target {
			left = mid + 1
		} else {
			break
		}
	}

	if mid >= len(nums) || nums[mid] != target {
		return []int{-1, -1}
	}

	leftTar := mid
	rightTar := mid

	for left < leftTar-1 {
		leftMid := left + (leftTar-left)/2
		if nums[leftMid] != target {
			left = leftMid + 1
		} else {
			leftTar = leftMid
		}
	}
	if nums[left] == target {
		leftTar = left
	}

	for rightTar < right-1 {
		rightMid := rightTar + (right-rightTar)/2
		if nums[rightMid] != target {
			right = rightMid - 1
		} else {
			rightTar = rightMid
		}
	}
	if nums[right] == target {
		rightTar = right
	}

	return []int{leftTar, rightTar}
}
