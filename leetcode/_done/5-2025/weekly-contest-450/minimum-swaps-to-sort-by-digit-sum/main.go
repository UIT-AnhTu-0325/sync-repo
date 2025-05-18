package main

import "sort"

func main() {
	minSwaps([]int{37, 100})
}

func sumDigit(num int) int {
	sum := 0
	for num > 0 {
		sum += num % 10
		num /= 10
	}
	return sum
}

type CusSort []int

func (a CusSort) Len() int      { return len(a) }
func (a CusSort) Swap(i, j int) { a[i], a[j] = a[j], a[i] }
func (a CusSort) Less(i, j int) bool {
	sumi := sumDigit(a[i])
	sumj := sumDigit(a[j])
	return (sumi < sumj) || (sumi == sumj && a[i] < a[j])
}

func minSwaps(nums []int) int {
	res := 0

	dicIdx := make(map[int]int)
	for i := range nums {
		dicIdx[nums[i]] = i
	}
	sort.Sort(CusSort(nums))

	visisted := make([]bool, len(nums))

	for i := range nums {
		resI := calc(dicIdx, nums, visisted, 0, i)
		if resI > 0 {
			resI -= 1
		}
		res += resI
	}

	return res
}

func calc(dicIdx map[int]int, nums []int, visisted []bool, crrLen int, crrIdx int) int {
	if dicIdx[nums[crrIdx]] == crrIdx {
		return crrLen
	}
	if visisted[crrIdx] {
		return crrLen
	}
	visisted[crrIdx] = true
	return calc(dicIdx, nums, visisted, crrLen+1, dicIdx[nums[crrIdx]])
}
