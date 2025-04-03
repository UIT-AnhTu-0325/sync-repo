package main

import "sort"

func threeSum(nums []int) [][]int {
	res := make([][]int, 0)
	n := len(nums)
	sort.Ints(nums)
	for i := 0; i < n-1; i++ {
		start := i + 1
		end := n - 1
		for start < end {
			sum := nums[start] + nums[end] + nums[i]
			if sum > 0 {
				end--
			} else if sum < 0 {
				start++
			} else {
				res = append(res, []int{nums[start], nums[end], nums[i]})
				crrStart := start
				crrEnd := end
				for start < end && nums[start] == nums[crrStart] {
					start++
				}
				for start < end && nums[end] == nums[crrEnd] {
					end--
				}
			}
		}
		for i+1 < n && nums[i] == nums[i+1] {
			i++
		}
	}

	return res
}

func main() {
	nums := []int{-1, 0, 1, 2, -1, -4}
	threeSum(nums)
}
