package main

func main() {

}

func isAnagram(s string, t string) bool {
	mem1 := make(map[byte]int)
	mem2 := make(map[byte]int)
	if len(s) != len(t) {
		return false
	}
	for i := range s {
		mem1[s[i]]++
		mem2[t[i]]++
	}
	for i := range mem1 {
		if mem1[i] != mem2[i] {
			return false
		}
	}
	return true
}
