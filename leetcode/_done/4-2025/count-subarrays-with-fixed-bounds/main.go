package main

func main() {
	countSubarrays([]int{1, 3, 5, 2, 7, 5}, 1, 5)
}

func countSubarrays(nums []int, minK int, maxK int) int64 {
	crr := 0
	res := int64(0)
	crrMin, crrMax := -1, -1
	left := 0
	for crr < len(nums) {
		if nums[crr] == maxK {
			crrMax = crr
		}
		if nums[crr] == minK {
			crrMin = crr
		}
		if nums[crr] > maxK || nums[crr] < minK {
			crr++
			left = crr
			continue
		}
		if left <= min(crrMin, crrMax) {
			res += int64(min(crrMin, crrMax) - left)
			res++
		}
		crr++
	}
	return res
}
