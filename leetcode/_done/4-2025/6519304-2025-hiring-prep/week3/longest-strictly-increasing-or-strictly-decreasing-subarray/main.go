package main

func longestMonotonicSubarray(nums []int) int {
	res, cntDec, cntInc := 0, 1, 1

	for i := 1; i < len(nums); i++ {
		if nums[i] > nums[i-1] {
			cntInc++
			cntDec = 1
		} else if nums[i] < nums[i-1] {
			cntDec++
			cntInc = 1
		} else {
			cntDec = 1
			cntInc = 1
		}
		res = _max(res, cntDec)
		res = _max(res, cntInc)
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
	_ = longestMonotonicSubarray
}
