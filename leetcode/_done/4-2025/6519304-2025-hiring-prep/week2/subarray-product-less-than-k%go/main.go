package main

func numSubarrayProductLessThanK(nums []int, k int) int {
	crrPro, i, j, res := 1, 0, 0, 0
	for j < len(nums) {
		crrPro *= nums[j]
		for crrPro >= k && i < j {
			crrPro /= nums[i]
			i++
		}
		if crrPro >= k {
			j++
			continue
		}
		res += (j - i + 1)
		j++
	}
	return res
}

func main() {
	numSubarrayProductLessThanK([]int{10, 5, 2, 6}, 100)
}
