package main

func main() {

}

func calc(x float64, n int) float64 {
	if n == 0 {
		return 1
	}
	if n == 1 {
		return x
	}

	h := calc(x, n/2)

	if n%2 != 0 {
		return h * h * x
	}
	return h * h
}

func myPow(x float64, n int) float64 {
	if n > 0 {
		return calc(x, n)
	}
	return 1 / calc(x, (-n))
}
