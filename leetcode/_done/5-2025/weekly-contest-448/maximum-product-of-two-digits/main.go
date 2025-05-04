package main

import "math"

func main() {

}
func maxProduct(n int) int {
	first := math.MinInt
	sec := math.MinInt
	for n > 0 {
		p := n % 10
		if sec < p {
			sec = p
		}
		if first < p {
			sec = first
			first = p
		}
		n /= 10
	}
	return first * sec
}
