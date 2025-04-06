package main

import "math"

func main() {
	_ = maxProduct([]int{7, 8, 12, 2, 9, 0, 5, 12, 10, 1, 11, 9, 5, 9, 7, 12, 12, 12, 6, 7, 5, 7, 9, 2, 7, 7, 11, 8, 9, 1, 6, 12, 11, 6, 1, 4, 2, 6, 5, 4}, 15, 100)
	// 	[7,8,12,2,9,0,5,12,10,1,11,9,5,9,7,12,12,12,6,7,5,7,9,2,7,7,11,8,9,1,6,12,11,6,1,4,2,6,5,4]
	// 15
	// 100
}

type Pair struct {
	idx    int
	isEven bool
}

func maxProduct(nums []int, k int, limit int) int {
	pick := calc(nums, k, limit, 0, 0, 1, 0, make(map[Pair]int))
	if pick == math.MinInt {
		return -1
	}
	return pick
}

func calc(nums []int, k int, limit int, crrIdx int, crrSum int, crrProd int, crrCount int, mem map[Pair]int) int {
	if crrIdx >= len(nums) {
		return math.MinInt
	}

	isEven := crrCount%2 == 0
	if val, ex := mem[Pair{idx: crrIdx, isEven: isEven}]; ex {
		return val
	}

	sum := crrSum
	prod := crrProd

	if crrCount%2 == 0 {
		sum += nums[crrIdx]
	} else {
		sum -= nums[crrIdx]
	}
	prod *= nums[crrIdx]

	maxStophere, maxPick, maxNotPic := 0, 0, 0
	if sum == k && prod <= limit {
		maxStophere = prod
	} else {
		maxStophere = math.MinInt
	}

	maxPick = calc(nums, k, limit, crrIdx+1, sum, prod, crrCount+1, mem)
	maxNotPic = calc(nums, k, limit, crrIdx+1, crrSum, crrProd, crrCount, mem)

	res := max(maxStophere, maxPick, maxNotPic)

	mem[Pair{idx: crrIdx, isEven: isEven}] = res

	return res
}
