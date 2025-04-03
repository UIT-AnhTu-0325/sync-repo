package main

func rankTeams(votes []string) string {
	res := ""
	mem := make([][]int, 27)
	for i := range mem {
		mem[i] = make([]int, 29)
		for j := range mem[i] {
			mem[i][j] = 0
		}
		mem[i][27] = i
		mem[i][28] = -1
	}

	for _, vote := range votes {
		for i, char := range vote {
			charIdx := int(char - 'A')
			mem[charIdx][i]++
			mem[charIdx][28] = 1
		}
	}

	for i := 0; i < len(mem); i++ {
		if mem[i][28] == -1 {
			mem = append(mem[:i], mem[i+1:]...)
			i--
		}
	}

	for i := 0; i < len(mem); i++ {
		for j := i + 1; j < len(mem); j++ {
			if !greater(mem[i], mem[j]) {
				tmpI := make([]int, 29)
				tmpJ := make([]int, 29)
				copy(tmpI, mem[i])
				copy(tmpJ, mem[j])
				copy(mem[i], tmpJ)
				copy(mem[j], tmpI)
			}
		}
	}

	for i := range mem {
		if mem[i][28] == -1 {
			continue
		}
		res += string(rune('A' + mem[i][27]))
	}

	return res
}

func greater(first []int, second []int) bool {
	for i := 0; i < 27; i++ {
		if first[i] > second[i] {
			return true
		} else if first[i] < second[i] {
			return false
		}
	}
	return first[27] < second[27]
}

func main() {
	_ = rankTeams([]string{"ABC", "ACB", "ABC", "ACB", "ACB"})
}
