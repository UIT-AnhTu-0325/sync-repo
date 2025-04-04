package main

func rob(nums []int) int {
	return calc(nums, 0, make(map[int]int))
}

func calc(nums []int, index int, mem map[int]int) int {
	if index >= len(nums) {
		return 0
	}
	if val, ex := mem[index]; ex {
		return val
	}
	pick := calc(nums, index+2, mem) + nums[index]
	notPick := calc(nums, index+1, mem)
	res := max(pick, notPick)
	mem[index] = res
	return res
}
