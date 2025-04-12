package main

import (
	"fmt"
	"math/big"
	"sort"
)

type Solution struct {
	res     int64
	visited map[string]bool
}

// Helper to convert a slice of digits into a number
func vectorToNumber(nums []int) int64 {
	var res int64 = 0
	for _, dig := range nums {
		res = res*10 + int64(dig)
	}
	return res
}

// Factorial using big.Int to handle large numbers
func fact(n int) *big.Int {
	f := big.NewInt(1)
	for i := 2; i <= n; i++ {
		f.Mul(f, big.NewInt(int64(i)))
	}
	return f
}

// Total permutations of digits in a map
func totalPermutations(digMap map[int]int, total int) *big.Int {
	totalDig := fact(total)
	for _, count := range digMap {
		totalDig.Div(totalDig, fact(count))
	}
	return totalDig
}

// Permutations excluding those starting with zero
func permsWithZero(digMap map[int]int, total int) *big.Int {
	if digMap[0] == 0 {
		return big.NewInt(0)
	}
	digMap[0]--
	defer func() { digMap[0]++ }()

	tot := fact(total - 1)
	for _, count := range digMap {
		tot.Div(tot, fact(count))
	}
	return tot
}

// Generate palindromes recursively
func (s *Solution) genPal(palin []int, left, right, divisor, total int) {
	if left > right {
		palinVal := vectorToNumber(palin)
		if palinVal%int64(divisor) == 0 {
			digMap := make(map[int]int)
			tmp := palinVal
			for tmp > 0 {
				digMap[int(tmp%10)]++
				tmp /= 10
			}
			key := mapKey(digMap)
			if !s.visited[key] {
				totalPerms := totalPermutations(digMap, total)
				permsZero := permsWithZero(digMap, total)
				diff := new(big.Int).Sub(totalPerms, permsZero)
				s.res += diff.Int64()
				s.visited[key] = true
			}
		}
		return
	}
	for dig := 0; dig <= 9; dig++ {
		if left == 0 && dig == 0 {
			continue
		}
		palin[left] = dig
		palin[right] = dig
		s.genPal(palin, left+1, right-1, divisor, total)
	}
}

// Convert a digit map to a sorted string key for uniqueness
func mapKey(m map[int]int) string {
	var keys []int
	for k := range m {
		keys = append(keys, k)
	}
	sort.Ints(keys)
	result := ""
	for _, k := range keys {
		result += fmt.Sprintf("%d:%d;", k, m[k])
	}
	return result
}

// Entry function to count good integers
func (s *Solution) countGoodIntegersSolution(total, divisor int) int64 {
	s.visited = make(map[string]bool)
	palin := make([]int, total)
	s.genPal(palin, 0, total-1, divisor, total)
	return s.res
}

func countGoodIntegers(total, divisor int) int64 {
	sol := &Solution{}
	result := sol.countGoodIntegersSolution(total, divisor)
	return result
}

func main() {
	_ = countGoodIntegers
}
