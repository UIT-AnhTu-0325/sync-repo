package main

func main() {

}

func nextGreatestLetter(letters []byte, target byte) byte {
	left := 0
	right := len(letters) - 1

	for left < right {
		mid := (right + left) / 2
		if letters[mid] <= target {
			left = mid + 1
		} else {
			right = mid
		}
	}

	if letters[right] > target {
		return letters[right]
	}

	return letters[0]
}
