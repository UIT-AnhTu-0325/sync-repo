package main

func main() {
	_ = intersection([]int{1, 2, 2, 1}, []int{2, 2})
}

func intersection(nums1 []int, nums2 []int) []int {
	map1 := make(map[int]bool)
	for i := range nums1 {
		map1[nums1[i]] = true
	}
	map2 := make(map[int]bool)
	for i := range nums2 {
		map2[nums2[i]] = true
	}

	res := make([]int, 0)
	for i := range map1 {
		if _, ex := map2[i]; ex {
			res = append(res, i)
		}
	}
	return res
}
