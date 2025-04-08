package main

func main() {
}

/**
 * Forward declaration of isBadVersion API.
 * @param   version   your guess about first bad version
 * @return 	 	      true if current version is bad
 *			          false if current version is good
 * func isBadVersion(version int) bool;
 */
func isBadVersion(version int) bool

func firstBadVersion(n int) int {
	left := 1
	right := n

	for left < right {
		next := left + (right-left)/2
		if isBadVersion(next) {
			right = next
		} else {
			left = next + 1
		}
	}

	if isBadVersion(left) {
		return left
	}
	return -1
}
