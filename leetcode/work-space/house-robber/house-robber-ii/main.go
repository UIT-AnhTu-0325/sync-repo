package main

import "math"

type Pair struct {
	index  int
	isPick bool
}

func rob(nums []int) int {
	if len(nums) == 1 {
		return nums[0]
	}
	return calc(nums, 0, make(map[Pair]int), true)
}

func calc(nums []int, index int, mem map[Pair]int, isPickFirst bool) int {
	if index >= len(nums) {
		return 0
	}
	if val, ex := mem[Pair{index: index, isPick: isPickFirst}]; ex {
		return val
	}
	pick := 0
	notPick := 0
	if index == 0 {
		pick = calc(nums, index+2, mem, true) + nums[index]
	} else {
		pick = calc(nums, index+2, mem, isPickFirst) + nums[index]
	}
	if isPickFirst && index == len(nums)-1 {
		pick = math.MinInt
	}
	if index == 0 {
		notPick = calc(nums, index+1, mem, false)
	} else {
		notPick = calc(nums, index+1, mem, isPickFirst)
	}

	res := max(pick, notPick)
	mem[Pair{index: index, isPick: isPickFirst}] = res
	return res
}

func main() {
	_ = rob([]int{1, 2, 3})
}
