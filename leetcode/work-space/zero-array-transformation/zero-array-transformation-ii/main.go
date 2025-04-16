package main

func main() {
	_ = minZeroArray([]int{7, 6, 8}, [][]int{{0, 0, 2}, {0, 1, 5}, {2, 2, 5}, {0, 2, 4}})
	_ = minZeroArray_1
}

func minZeroArray_1(nums []int, queries [][]int) int {
	left := 0
	right := len(queries)

	mem := make([]int, len(nums)+1)
	for left <= right {
		mem = make([]int, len(nums)+1)
		mid := left + (right-left)/2
		for i := range mid {
			mem[queries[i][0]] -= queries[i][2]
			mem[queries[i][1]+1] += queries[i][2]
		}
		if !isZero(nums, mem) {
			left = mid + 1
		} else {
			right = mid - 1
		}
	}
	if left >= len(queries) && !isZero(nums, mem) {
		return -1
	}
	return left
}

func isZero(nums []int, mem []int) bool {
	crrMinus := 0
	for i := range nums {
		crrMinus += mem[i]
		if crrMinus+nums[i] > 0 {
			return false
		}
	}
	return true
}

func minZeroArray(nums []int, queries [][]int) int {
	crrSum := 0
	crrQuery := 0
	mem := make([]int, len(nums)+1)
	for i := range nums {
		for crrSum+mem[i] < nums[i] {
			crrQuery++
			if crrQuery > len(queries) {
				return -1
			}
			left := queries[crrQuery-1][0]
			right := queries[crrQuery-1][1]
			val := queries[crrQuery-1][2]

			if right >= i {
				mem[right+1] -= val
				mem[max(left, i)] += val
			}
		}
		crrSum += mem[i]
	}
	return crrQuery
}
