package main

func main() {

}

func findClosest(x int, y int, z int) int {
	disx := _abs(z - x)
	disy := _abs(z - y)
	if disx == disy {
		return 0
	} else if disx > disy {
		return 2
	} else {
		return 1
	}
}

func _abs(n int) int {
	if n < 0 {
		return -n
	}
	return n
}
