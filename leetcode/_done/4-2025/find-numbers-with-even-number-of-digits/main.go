package main

func main() {

}

func findNumbers(nums []int) int {
	res := 0
	for i := range nums {
		if calc(nums[i]) {
			res++
		}
	}
	return res
}

func calc(num int) bool {
	cnt := 0
	for num > 0 {
		cnt++
		num /= 10
	}
	return cnt%2 == 0
}
