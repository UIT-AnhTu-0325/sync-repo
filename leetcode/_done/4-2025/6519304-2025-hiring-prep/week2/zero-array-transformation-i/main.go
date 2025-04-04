package main

func isZeroArray(nums []int, queries [][]int) bool {

	decree := make([]int, len(nums)+1)
	for i := range decree {
		decree[i] = 0
	}
	for _, query := range queries {
		decree[query[0]]--
		decree[query[1]+1]++
	}
	crrDecree := 0
	for i := 0; i < len(nums); i++ {
		crrDecree += decree[i]
		if nums[i]+crrDecree > 0 {
			return false
		}
	}
	return true
}

func main() {
	_ = isZeroArray([]int{4, 3, 2, 1}, [][]int{{1, 3}, {0, 2}})
}
