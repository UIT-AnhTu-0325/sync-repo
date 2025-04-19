package main

import "sort"

func main() {
	countFairPairs([]int{6, 9, 4, 2, 7, 5, 10, 3}, 13, 13)
}

func countFairPairs(nums []int, lower int, upper int) int64 {
	sort.Ints(nums)
	res := int64(0)
	left, low, up := 0, len(nums)-1, len(nums)-1
	for left < len(nums) {
		for low >= 0 && nums[left]+nums[low] >= lower {
			low--
		}
		for up >= 0 && nums[left]+nums[up] > upper {
			up--
		}
		res += int64(up - low)
		if left <= up && left > low {
			res -= 1
		}
		left++
	}
	return res / 2
}
