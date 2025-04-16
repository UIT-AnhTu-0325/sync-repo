package main

import "strings"

func main() {

}

func wordPattern(pattern string, s string) bool {
	arr := strings.Split(s, " ")
	if len(arr) != len(pattern) {
		return false
	}
	mem1 := make(map[byte]string)
	mem2 := make(map[string]byte)
	for i := range arr {
		if val1, ex1 := mem1[pattern[i]]; ex1 {
			if val1 != arr[i] {
				return false
			}
		} else {
			mem1[pattern[i]] = arr[i]
		}

		if val2, ex2 := mem2[arr[i]]; ex2 {
			if val2 != pattern[i] {
				return false
			}
		} else {
			mem2[arr[i]] = pattern[i]
		}
	}
	return true
}
