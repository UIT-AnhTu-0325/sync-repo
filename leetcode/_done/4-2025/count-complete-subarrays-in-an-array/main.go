package main

func main() {
	countCompleteSubarrays([]int{5, 5, 5, 5})
}

func countCompleteSubarrays(nums []int) int {
	cnt := 0
	mem := make(map[int]bool)
	for i := range nums {
		if !mem[nums[i]] {
			cnt++
			mem[nums[i]] = true
		}
	}

	l, r := 0, 0
	crrMem := make(map[int]int)
	total := 0
	res := 0
	for r < len(nums) {
		if _, ex := crrMem[nums[r]]; !ex {
			total++
			crrMem[nums[r]] = 1
		} else {
			crrMem[nums[r]]++
		}

		for total == cnt {
			res += len(nums) - r
			crrMem[nums[l]]--
			if crrMem[nums[l]] == 0 {
				total--
				delete(crrMem, nums[l])
			}
			l++
		}
		r++
	}
	return res
}
