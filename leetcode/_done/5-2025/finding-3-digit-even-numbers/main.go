package main

import "sort"

func main() {
	findEvenNumbers([]int{2, 2, 8, 8, 2})
}

func findEvenNumbers(digits []int) []int {
	sort.Ints(digits)
	res := make([]int, 0)
	for i := range digits {
		if digits[i] == 0 {
			continue
		}
		for j := range digits {
			if j == i || (j > 0 && digits[j-1] == digits[j]) {
				continue
			}
			for k := range digits {
				if k == i || k == j || (k > 0 && digits[k-1] == digits[k]) {
					continue
				}
				if digits[k]%2 != 0 {
					continue
				}
				res = append(res, digits[i]*100+digits[j]*10+digits[k])
			}
		}
	}
	return res
}
