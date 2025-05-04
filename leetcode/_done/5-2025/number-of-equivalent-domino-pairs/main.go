package main

func main() {

}

type key struct {
	min int
	max int
}

func numEquivDominoPairs(dominoes [][]int) int {
	mem := make(map[key]int)
	for i := range dominoes {
		min := min(dominoes[i][0], dominoes[i][1])
		max := max(dominoes[i][0], dominoes[i][1])
		key := key{min: min, max: max}
		mem[key]++
	}
	res := 0
	for i := range mem {
		res += mem[i] * (mem[i] - 1) / 2
	}
	return res
}
