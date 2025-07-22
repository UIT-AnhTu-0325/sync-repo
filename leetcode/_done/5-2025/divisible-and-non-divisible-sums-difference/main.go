package main

func main() {

}

func differenceOfSums(n int, m int) int {
	total := n * (n + 1) / 2
	divi := m * (n / m) * (n/m + 1)
	return total - divi
}
