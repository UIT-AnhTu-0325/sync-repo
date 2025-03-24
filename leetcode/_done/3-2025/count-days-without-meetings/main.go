package main

import (
	"math"
	"sort"
)

func countDays(days int, meetings [][]int) int {
	mem := make(map[int]int)
	crrCountDay := math.MaxInt
	for _, item := range meetings {
		s, e := item[0], item[1]+1
		crrCountDay = _min(crrCountDay, s)
		if _, exists := mem[s]; exists {
			mem[s]--
		} else {
			mem[s] = -1
		}
		if _, exists := mem[e]; exists {
			mem[e]++
		} else {
			mem[e] = 1
		}
	}
	res := crrCountDay - 1
	crrSum := 0

	keys := make([]int, 0, len(mem))
	for k := range mem {
		keys = append(keys, k)
	}
	sort.Ints(keys)

	for _, k := range keys {
		if (crrSum) == 0 {
			res += k - crrCountDay
		}
		crrSum += mem[k]
		crrCountDay = k
	}
	res += days - crrCountDay + 1
	return res
}

func _min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {

}
