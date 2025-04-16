package main

func main() {

}

func plusOne(digits []int) []int {
	isBorrow := true
	for i := len(digits) - 1; i >= 0; i-- {
		if isBorrow {
			digits[i]++
			if digits[i] == 10 {
				digits[i] = 0
				isBorrow = true
			} else {
				isBorrow = false
			}
		} else {
			break
		}
	}
	if isBorrow {
		return append([]int{1}, digits...)
	} else {
		return digits
	}
}
