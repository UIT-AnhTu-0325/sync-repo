package main

func rankTeams(votes []string) string {
	res := ""
	mem := make([][]int, 27)
	max := make([]int, 27)
	for i := range max {
		max[i] = -1
	}
	for i := range mem {
		mem[i] = make([]int, 27)
		for j := range mem[i] {
			mem[i][j] = 0
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
	_ = rankTeams
}
