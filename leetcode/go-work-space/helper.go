//go:build ignore

package main

import (
	"slices"
	"sort"
)

type Pair struct {
	first  int
	second int
}

func _createPairs(firsts []int, seconds []int, quantity int) []Pair {
	pairs := make([]Pair, quantity)
	for i := 0; i < quantity; i++ {
		pairs[i] = Pair{first: firsts[i], second: seconds[i]}
	}
	return pairs
}

func _sortPair(firsts []int, seconds []int) []Pair {
	quantity := len(firsts)
	pairs := _createPairs(firsts, seconds, quantity)

	sort.Slice(pairs, func(i, j int) bool {
		return pairs[i].second > pairs[j].second
	})
	return pairs
}

func _max(nums ...int) int {
	return slices.Max(nums)
}

func _min(nums ...int) int {
	return slices.Min(nums)
}

func _abs(n int) int {
	if n < 0 {
		return -n
	}
	return n
}

func _minDistanceCircular(n, i, j int) int {
	forward := (j - i + n) % n
	backward := (i - j + n) % n
	return min(forward, backward)
}
