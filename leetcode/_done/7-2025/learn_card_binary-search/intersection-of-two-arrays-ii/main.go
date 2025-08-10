package main

func main() {

}

func intersect(nums1 []int, nums2 []int) []int {
	map1 := make(map[int]int)
	for i := range nums1 {
		map1[nums1[i]]++
	}
	map2 := make(map[int]int)
	for i := range nums2 {
		map2[nums2[i]]++
	}

	res := make([]int, 0)
	for i := range map1 {
		if _, ex := map2[i]; ex {
			for j := 0; j < min(map1[i], map2[i]); j++ {
				res = append(res, i)
			}
		}
	}
	return res
}
