package main

import "sort"

func sortString(s string) string {
	// Convert string to a slice of runes (supports Unicode characters)
	runes := []rune(s)

	// Sort the slice
	sort.Slice(runes, func(i, j int) bool {
		return runes[i] < runes[j]
	})

	// Convert back to string
	return string(runes)
}
func groupAnagrams(strs []string) [][]string {
	mapStrs := make(map[string][]string)

	for _, str := range strs {
		key := sortString(str)
		mapItem, exists := mapStrs[key]
		if !exists {
			mapStrs[key] = make([]string, 0)
		}
		mapItem = append(mapItem, str)
		mapStrs[key] = mapItem
	}

	res := make([][]string, 0)
	for key := range mapStrs {
		res = append(res, mapStrs[key])
	}
	return res
}

func main() {
	_ = groupAnagrams
}
