package main

import "math"

func main() {

}

func minDominoRotations(tops []int, bottoms []int) int {
	res := math.MaxInt
	for val := 1; val <= 6; val++ {
		i := 0
		crr := 0
		for i < len(tops) {
			if tops[i] == val {
				i++
				continue
			} else if bottoms[i] == val {
				i++
				crr++
			} else {
				break
			}
		}
		if i == len(tops) {
			res = min(res, crr)
		}
	}
	for val := 1; val <= 6; val++ {
		i := 0
		crr := 0
		for i < len(tops) {
			if bottoms[i] == val {
				i++
				continue
			} else if tops[i] == val {
				i++
				crr++
			} else {
				break
			}
		}
		if i == len(tops) {
			res = min(res, crr)
		}
	}

	if res == math.MaxInt {
		return -1
	}

	return res
}
