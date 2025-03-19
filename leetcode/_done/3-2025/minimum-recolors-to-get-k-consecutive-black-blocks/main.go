package main

import "math"

func minimumRecolors(blocks string, k int) int {
	res := math.MaxInt32
	crrCount := 0
	idx := 0
	for ; idx < k; idx++ {
		if blocks[idx] == 'W' {
			crrCount++
		}
	}
	res = _min(res, crrCount)
	for ; idx < len(blocks); idx++ {
		if blocks[idx] == 'W' {
			crrCount++
		}
		if blocks[idx-k] == 'W' {
			crrCount--
		}
		res = _min(res, crrCount)
	}
	return res
}

func _min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	_ = minimumRecolors
}
