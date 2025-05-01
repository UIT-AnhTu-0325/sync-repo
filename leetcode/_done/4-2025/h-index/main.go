package main

import "sort"

func main() {

}

func hIndex(citations []int) int {
	sort.Ints(citations)
	cnt := 0
	for i := len(citations) - 1; i >= 0; i-- {
		cnt++
		if citations[i] == cnt {
			return citations[i]
		} else if cnt > citations[i] {
			if i+1 >= len(citations) {
				return cnt - 1
			} else {
				return min(cnt-1, citations[i+1])
			}
		}
	}
	return cnt
}
