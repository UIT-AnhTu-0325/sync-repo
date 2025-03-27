package main

func numberOfSubsequences(nums []int) int64 {
	mem := make(map[float64]int64)
	n := len(nums)
	res := int64(0)
	for r := 4; r < n-2; r++ {
		q := r - 2
		for p := 0; p < r-3; p++ {
			d := float64(nums[p]) / float64(nums[q])
			if _, ex := mem[d]; !ex {
				mem[d] = 0
			}
			mem[d]++
		}
		for s := r + 2; s < n; s++ {
			d := float64(nums[s]) / float64(nums[r])
			if val, ex := mem[d]; ex {
				res += val
			}
		}
	}
	return res
}

func main() {
	_ = numberOfSubsequences([]int{1, 2, 3, 4, 3, 6, 1})
}
