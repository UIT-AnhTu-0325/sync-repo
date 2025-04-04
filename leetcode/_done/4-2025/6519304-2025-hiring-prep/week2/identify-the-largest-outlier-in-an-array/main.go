package main

import "math"

func getLargestOutlier(nums []int) int {
	mem := make(map[int]int)
	sum := 0
	for _, num := range nums {
		sum += num
		mem[num]++
	}
	res := math.MinInt
	for _, num := range nums {
		if (sum-num)%2 != 0 {
			continue
		}
		if (sum-num)/2 == num && mem[(sum-num)/2] > 1 {
			res = _max(res, num)
		} else if (sum-num)/2 != num {
			if val, ex := mem[(sum-num)/2]; ex && val > 0 {
				res = _max(res, num)
			}
		}
	}
	return res
}

func _max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	_ = getLargestOutlier([]int{6, -31, 50, -35, 41, 37, -42, 13})
}
