package main

type Pair struct {
	start, end int
}

func countPalindromicSubsequence(s string) int {
	mem := make(map[byte]Pair)
	abcMem := [][]int{make([]int, 30)}
	res := 0
	for idx := range s {
		if _, e := mem[s[idx]]; !e {
			mem[s[idx]] = Pair{idx, -1}
		} else {
			tmp := mem[s[idx]]
			tmp.end = idx
			mem[s[idx]] = tmp
		}
		befmem := abcMem[idx]
		crrMem := make([]int, 30)
		copy(crrMem, befmem)
		crrMem[int(s[idx]-'a')] += 1
		abcMem = append(abcMem, crrMem)
	}
	for item := range mem {
		if mem[item].end != -1 {
			distinc := 0
			for i := 0; i < 30; i++ {
				if abcMem[mem[item].end][i] > abcMem[mem[item].start+1][i] {
					distinc++
				}
			}
			res += distinc
		}
	}
	return res
}
func main() {
	_ = countPalindromicSubsequence("bbcbaba")
}
