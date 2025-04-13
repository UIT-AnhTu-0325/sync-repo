package main

import (
	"sort"
	"strings"
)

func main() {
	smallestPalindrome("yey")
}

func smallestPalindrome(s string) string {
	runes := []rune(s)
	sort.Slice(runes, func(i, j int) bool {
		return runes[i] < runes[j]
	})

	mid := '-'
	var left, right strings.Builder

	for i := 0; i < len(runes); i++ {
		if i == len(runes)-1 {
			mid = runes[i]
			break
		}
		if runes[i+1] == runes[i] {
			left.WriteRune(runes[i])
			right.WriteRune(runes[i+1])
			i++
		} else {
			mid = runes[i]
		}
	}

	// Build final string
	var result strings.Builder
	result.WriteString(left.String())
	if mid != '-' {
		result.WriteRune(mid)
	}
	// Append the reverse of right.String()
	rightRunes := []rune(right.String())
	for i := len(rightRunes) - 1; i >= 0; i-- {
		result.WriteRune(rightRunes[i])
	}

	return result.String()
}
