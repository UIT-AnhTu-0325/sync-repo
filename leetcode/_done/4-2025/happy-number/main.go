package main

func main() {

}

func isHappy(n int) bool {
	mem := make(map[int]bool)
	for n != 1 {
		if _, ex := mem[n]; ex {
			return false
		}
		mem[n] = true
		newN := 0
		for n > 0 {
			newN += (n % 10) * (n % 10)
			n /= 10
		}
		n = newN
	}
	if n == 1 {
		return true
	}
	return false
}
