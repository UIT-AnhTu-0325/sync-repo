package main

func isPan(s string) bool {
	for i := 0; i < len(s)/2; i++ {
		if s[i] != s[len(s)-i-1] {
			return false
		}
	}
	return true
}

func longestPalindrome(s string, t string) int {

	res := 0

	for i := 0; i < len(s); i++ {
		for j := len(s); j >= i; j-- {
			for m := 0; m < len(t); m++ {
				for n := len(t); n >= m; n-- {
					s1 := s[i:j]
					t1 := t[m:n]
					if isPan(s1 + t1) {
						res = _max(res, len(s1+t1))
					}
				}
			}
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
