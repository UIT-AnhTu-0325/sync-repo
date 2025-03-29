package main

import "sort"

type Pair struct {
	start int
	end   int
}

func merge(intervals [][]int) [][]int {
	pairs := make([]Pair, 0)
	for _, in := range intervals {
		pairs = append(pairs, Pair{start: in[0], end: in[1]})
	}
	sort.Slice(pairs, func(i, j int) bool {
		if pairs[i].start != pairs[j].start {
			return pairs[i].start < pairs[j].start
		}
		return pairs[i].end < pairs[j].end
	})

	idx := 0
	for idx < len(pairs)-1 {
		if pairs[idx].end >= pairs[idx+1].start {
			pairs[idx].end = _max(pairs[idx].end, pairs[idx+1].end)
			pairs = append(pairs[0:idx+1], pairs[idx+2:]...)
		} else {
			idx++
		}
	}
	res := make([][]int, 0)
	for _, pair := range pairs {
		res = append(res, []int{pair.start, pair.end})
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

}
