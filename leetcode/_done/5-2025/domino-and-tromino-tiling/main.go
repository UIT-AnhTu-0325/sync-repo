package main

func main() {

}

var mem = make(map[int]int)
var mod = 1e9 + 7

func numTilings(n int) int {
	if n == 1 {
		return 1
	}
	if n == 2 {
		return 2
	}
	if n == 3 {
		return 5
	}
	if val, ex := mem[n]; ex {
		return val
	}
	res := float64(int64((2*numTilings(n-1))+(numTilings(n-3))) % int64(mod))
	mem[n] = int(res)
	return mem[n]
}
