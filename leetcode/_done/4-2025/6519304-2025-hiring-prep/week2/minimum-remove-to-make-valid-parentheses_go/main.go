package main

func removeCharAtIndex(s string, i int) string {
	runes := []rune(s)
	if i < 0 || i >= len(runes) {
		return s
	}
	return string(runes[:i]) + string(runes[i+1:])
}

func minRemoveToMakeValid(s string) string {
	crrOpen := make([]int, 0)
	for i := 0; i < len(s); i++ {
		if s[i] != '(' && s[i] != ')' {
			continue
		} else if s[i] == ')' {
			if len(crrOpen) == 0 {
				s = removeCharAtIndex(s, i)
				i--
			} else {
				crrOpen = crrOpen[:len(crrOpen)-1]
			}
		} else if s[i] == '(' {
			crrOpen = append(crrOpen, i)
		}
	}

	for i := len(crrOpen) - 1; i >= 0; i-- {
		s = removeCharAtIndex(s, crrOpen[i])
	}
	return s
}

func main() {
	_ = minRemoveToMakeValid("))((")
}
