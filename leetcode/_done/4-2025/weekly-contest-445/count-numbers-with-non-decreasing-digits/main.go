package main

import (
	"fmt"
	"math/big"
)

func main() {
	countNumbers("23", "28", 8)
}

func countNumbers(l string, r string, b int) int {
	numLeft := new(big.Int)
	numLeft.SetString(l, 10)
	numLeft.Sub(numLeft, big.NewInt(1))

	return (int(countNonDecreasingNumbers(r, b)-countNonDecreasingNumbers(numLeft.String(), b)) + MOD) % MOD
}

const MOD = 1000000007 // Modulo 1e9 + 7

var dp map[string]int64
var base int
var digits []int

func countNonDecreasingNumbers(x string, b int) int64 {
	base = b
	dp = make(map[string]int64)
	digits = toBaseB(x, b)
	return dfs(0, 0, true)
}

func toBaseB(x string, b int) []int {
	n := new(big.Int)
	n.SetString(x, 10)
	zero := big.NewInt(0)
	bb := big.NewInt(int64(b))
	var res []int

	for n.Cmp(zero) > 0 {
		mod := new(big.Int)
		n.DivMod(n, bb, mod)
		res = append([]int{int(mod.Int64())}, res...)
	}
	return res
}

func dfs(pos, prev int, limitNow bool) int64 {
	if pos == len(digits) {
		return 1
	}

	key := fmt.Sprintf("%d-%d-%t", pos, prev, limitNow)
	if val, ex := dp[key]; ex {
		return val
	}

	var res int64
	limit := base - 1
	if limitNow {
		limit = digits[pos]
	}

	for d := prev; d <= limit; d++ {
		res += dfs(pos+1, d, limitNow && (d == limit))
		res %= MOD
	}

	dp[key] = res
	return res
}
