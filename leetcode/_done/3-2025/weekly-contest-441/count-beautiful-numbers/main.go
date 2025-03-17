package main

import "strconv"

type MemoKey struct {
	x, prod, sum, tight int
}

func beautifulNumbers(l int, r int) int {
	sr := strconv.Itoa(r)
	memo := make(map[MemoKey]int)
	right := solve(sr, 0, 1, 0, 1, memo)

	sl := strconv.Itoa(l - 1)
	memo = make(map[MemoKey]int)
	left := solve(sl, 0, 1, 0, 1, memo)

	return right - left
}
func solve(num string, x, prod, sum, tight int, memo map[MemoKey]int) int {
	if x >= len(num) {
		if sum != 0 && prod%sum == 0 {
			return 1
		}
		return 0
	}
	key := MemoKey{x, prod, sum, tight}
	if mRes, e := memo[key]; e {
		return mRes
	}
	limit := 9
	if tight == 1 {
		limit = int(num[x] - '0')
	}
	ans := 0
	for i := 0; i <= limit; i++ {
		newTight := 0
		if tight == 1 && i == limit {
			newTight = 1
		}
		if i == 0 && sum == 0 {
			ans += solve(num, x+1, prod, sum, newTight, memo)
		} else {
			ans += solve(num, x+1, prod*i, sum+i, newTight, memo)
		}
	}

	memo[key] = ans
	return ans
}

func main() {
	_ = beautifulNumbers(1234, 1200)
}
