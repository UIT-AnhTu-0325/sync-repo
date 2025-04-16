package main

func main() {
	countGood([]int{2, 1, 3, 1, 2, 2, 3, 3, 2, 2, 1, 1, 1, 3, 1}, 11)
}

func countGood(nums []int, k int) int64 {
	mem := make(map[int]int)
	res := int64(0)
	left, right := 0, 0
	crrPair := 0
	for left < len(nums) {
		if crrPair < k {
			if right < len(nums) {
				if _, ex := mem[nums[right]]; ex {
					crrPair += mem[nums[right]]
					mem[nums[right]]++
				} else {
					mem[nums[right]] = 1
				}
				right++
			} else {
				left++
			}
		} else {
			res += int64(len(nums) - right + 1)
			crrPair -= (mem[nums[left]] - 1)
			mem[nums[left]]--
			left++
		}
	}
	return res
}
