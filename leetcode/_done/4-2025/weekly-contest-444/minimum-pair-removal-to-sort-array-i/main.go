package main

import "math"

func main() {
	_ = minimumPairRemoval([]int{2, 2, -1, 3, -2, 2, 1, 1, 1, 0, -1})
}

func isOk(nums []int) bool {
	for i := 0; i < len(nums)-1; i++ {
		if nums[i] > nums[i+1] {
			return false
		}
	}
	return true
}

func minimumPairRemoval(nums []int) int {
	time := 0
	for !isOk(nums) {
		minIdx := 0
		minSum := math.MaxInt
		for i := 0; i < len(nums)-1; i++ {
			sum := nums[i] + nums[i+1]
			if sum < minSum {
				minSum = sum
				minIdx = i
			}
		}
		time++
		newNums := append(nums[0:minIdx], minSum)
		newNums = append(newNums, nums[minIdx+2:]...)
		nums = newNums
	}
	return time
}
