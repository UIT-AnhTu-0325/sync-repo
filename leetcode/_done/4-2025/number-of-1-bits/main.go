package main

func main() {

}

func hammingWeight(n int) int {
	cnt := 0
	for n > 0 {
		if n&1 == 1 {
			cnt++
		}
		n = n >> 1
	}
	return cnt
}
