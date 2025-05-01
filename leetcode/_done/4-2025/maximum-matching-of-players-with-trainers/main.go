package main

import "sort"

func main() {

}

func matchPlayersAndTrainers(g []int, s []int) int {
	sort.Ints(s)
	sort.Ints(g)

	iG := len(g) - 1
	iS := len(s) - 1
	for iG >= 0 && iS >= 0 {
		if s[iS] >= g[iG] {
			iS--
			iG--
		} else {
			iG--
		}
	}
	return len(s) - iS - 1
}
