package main

func main() {
	_ = minimumOperations([]int{8, 10, 7, 1, 5, 1, 8})
}

func minimumOperations(nums []int) int {
	mem := make(map[int]int)
	lastDup := -1
	for i := range nums {
		if val, ex := mem[nums[i]]; ex {
			lastDup = max(lastDup, val)
		}
		mem[nums[i]] = i
	}
	lastDup++
	if lastDup%3 == 0 {
		return lastDup / 3
	} else {
		return lastDup/3 + 1
	}
}
