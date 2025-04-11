package main

import (
	"math"
	"strconv"
)

func main() {
	_ = numberOfPowerfulInt
}

func numberOfPowerfulInt(start int64, finish int64, limit int, s string) int64 {
	startStr := strconv.FormatInt(start-1, 10)
	endStr := strconv.FormatInt(finish, 10)
	return calc(endStr, limit, s) - calc(startStr, limit, s)
}

func calc(num string, limit int, s string) int64 {
	if len(num) < len(s) {
		return 0
	}
	if len(num) == len(s) {
		if num >= s {
			return 1
		}
		return 0
	}
	suffix := num[len(num)-len(s):]
	preLen := len(num) - len(s)

	res := int64(0)

	for i := 0; i < preLen; i++ {
		digit := int(num[i] - '0')
		if limit < digit {
			res += int64(math.Pow(float64(limit+1), float64(preLen-1)))
			return res
		}
		res += int64(digit) * int64(math.Pow(float64(limit+1), float64(preLen-1-i)))
	}

	if suffix >= s {
		res++
	}
	return res
}
