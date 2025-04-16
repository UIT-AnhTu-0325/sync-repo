package main

func main() {

}
func _abs(n int) int {
	if n < 0 {
		return -n
	}
	return n
}
func countGoodTriplets(arr []int, a int, b int, c int) int {
	cnt := 0
	n := len(arr)
	for i := 0; i < n-2; i++ {
		for j := i + 1; j < n-1; j++ {
			if _abs(arr[i]-arr[j]) > a {
				continue
			} else {
				for k := j + 1; k < n; k++ {
					if _abs(arr[i]-arr[k]) <= c && _abs(arr[j]-arr[k]) <= b {
						cnt++
					}
				}
			}
		}
	}
	return cnt
}
