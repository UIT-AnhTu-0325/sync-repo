package main

func validPalindrome(s string) bool {
	i, j, deleted := 0, len(s)-1, false
	return solve(s, i, j, deleted)
}

func solve(s string, start int, end int, deleted bool) bool {
	if start >= end {
		return true
	}
	if s[start] != s[end] && deleted {
		return false
	}
	if s[start] != s[end] && !deleted {
		res1 := solve(s, start+1, end, true)
		res2 := solve(s, start, end-1, true)
		return res1 || res2
	}
	if s[start] == s[end] {
		res1 := solve(s, start+1, end-1, deleted)
		res2, res3 := false, false
		if !deleted {
			res2 = solve(s, start+1, end, true)
			res3 = solve(s, start, end-1, true)
		}
		return res1 || res2 || res3
	}
	return true
}

func main() {
	_ = validPalindrome("cxcaac")
}
