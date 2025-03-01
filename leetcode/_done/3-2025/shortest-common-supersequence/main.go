package main

func shortestCommonSupersequence(str1 string, str2 string) string {
	len1 := len(str1)
	len2 := len(str2)
	mem := make([][]int, len1+1)
	for i := range mem {
		mem[i] = make([]int, len2+1)
		mem[i][0] = i
	}

	for j := 0; j <= len2; j++ {
		mem[0][j] = j
	}

	for i := 1; i <= len1; i++ {
		for j := 1; j <= len2; j++ {
			if str1[i-1] == str2[j-1] {
				mem[i][j] = mem[i-1][j-1] + 1
			} else {
				mem[i][j] = _min(mem[i-1][j], mem[i][j-1]) + 1
			}
		}
	}

	i, j := len1, len2
	maxCommon := ""

	for i > 0 && j > 0 {
		nextChar := ""
		if str1[i-1] == str2[j-1] {
			nextChar = string(str1[i-1])
			i--
			j--
		} else {
			if mem[i-1][j] > mem[i][j-1] {
				nextChar = string(str1[i-1])
				i--
			} else {
				nextChar = string(str2[j-1])
				j--
			}
		}
		maxCommon = nextChar + maxCommon
	}

	for i > 0 {
		maxCommon = string(str1[i-1]) + maxCommon
		i--
	}

	for j > 0 {
		maxCommon = string(str2[j-1]) + maxCommon
		j--
	}
	return maxCommon
}

func _min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	_ = shortestCommonSupersequence("abac", "cab")
}
