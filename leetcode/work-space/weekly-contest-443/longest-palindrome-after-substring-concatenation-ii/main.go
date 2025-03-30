package main

import "slices"

func isPan(s string) bool {
	for i := 0; i < len(s)/2; i++ {
		if s[i] != s[len(s)-i-1] {
			return false
		}
	}
	return true
}

func longestPalindrome(s string, t string) int {
	ls, lt := len(s), len(t)
	mems := make([]int, ls+2)
	memt := make([]int, lt+2)
	mem := make([][]int, ls+2)
	for i := range mem {
		mem[i] = make([]int, lt+2)
	}

	for i := 0; i < ls; i++ {
		for j := ls; j >= i; j-- {
			if isPan(s[i:j]) {
				mems[i+1] = j - i
				break
			}
		}
	}
	mems[0] = mems[1]

	for i := 1; i <= lt; i++ {
		for j := 0; j <= i; j++ {
			if isPan(t[j:i]) {
				memt[i] = i - j
				break
			}
		}
	}
	memt[lt+1] = memt[lt]

	for i := 0; i <= ls+1; i++ {
		mem[i][0] = mems[i]
	}

	for j := 0; j <= lt+1; j++ {
		mem[ls+1][j] = memt[j]
	}

	res := 0

	for i := ls; i > 0; i-- {
		for j := 1; j <= lt; j++ {
			if s[i-1] != t[j-1] {
				mem[i][j] = _max(mems[i], memt[j])
			} else {
				mem[i][j] = _max(mems[i], memt[j], mem[i+1][j-1]+2)
			}

			res = _max(res, mem[i][j])
		}
	}

	return res
}

func _max(nums ...int) int {
	return slices.Max(nums)
}

func main() {
	// longestPalindrome("b", "aaaa")
	longestPalindrome("iiye", "i")
}
