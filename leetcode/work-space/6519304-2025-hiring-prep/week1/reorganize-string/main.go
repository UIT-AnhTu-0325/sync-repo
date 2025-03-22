package main

import "sort"

type Pair struct {
	key   int
	count int
}

func reorganizeString(s string) string {
	cChars := make([]Pair, 27)
	for idx := range cChars {
		cChars[idx].key = idx
	}
	for _, c := range s {
		cChars[int(c-'a')].count++
	}
	sort.Slice(cChars, func(i, j int) bool {
		return cChars[i].count > cChars[j].count
	})
	res := make([]string, cChars[0].count)
	for i := 0; i < len(res); i++ {
		res[i] = string(rune(cChars[0].key + 'a'))
	}

	crrIdx := 0

	for i := 1; i < len(cChars); i++ {
		for j := 0; j < cChars[i].count; j++ {
			res[crrIdx%len(res)] += string(rune(cChars[i].key + 'a'))
			crrIdx++
		}
	}

	if crrIdx < len(res)-1 {
		return ""
	}

	final := ""
	for _, item := range res {
		final += item
	}
	return final
}

func main() {
	_ = reorganizeString("aaab")
}
