package main

func main() {

}

func triangleType(nums []int) string {
	a := nums[0]
	b := nums[1]
	c := nums[2]
	if a+b <= c || a+c <= b || b+c <= a {
		return "none"
	}
	if a == b && b == c {
		return "equilateral"
	}
	if a == b || b == c || c == a {
		return "isosceles"
	}
	return "scalene"
}
