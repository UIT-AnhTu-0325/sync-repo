package main

func main() {
	// router := Constructor(3)     // Initialize Router with memoryLimit of 3.
	// router.AddPacket(1, 4, 90)   // Packet is added. Return True.
	// router.AddPacket(2, 5, 90)   // Packet is added. Return True.
	// router.AddPacket(1, 4, 90)   // This is a duplicate packet. Return False.
	// router.AddPacket(3, 5, 95)   // Packet is added. Return True
	// router.AddPacket(4, 5, 105)  // Packet is added, [1, 4, 90] is removed as number of packets exceeds memoryLimit. Return True.
	// router.ForwardPacket()       // Return [2, 5, 90] and remove it from router.
	// router.AddPacket(5, 2, 110)  // Packet is added. Return True.
	// router.GetCount(5, 100, 110) // The only packet with destination 5 and timestamp in the inclusive range [100, 110] is [4, 5, 105]. Return 1.

	// 	["Router","addPacket","addPacket","addPacket","addPacket","addPacket","forwardPacket","addPacket","getCount"]
	// [[3],[1,4,90],[2,5,90],[1,4,90],[3,5,95],[4,5,105],[],[5,2,110],[5,100,110]]

	// router := Constructor(2)   // Initialize Router with memoryLimit of 2.
	// router.AddPacket(7, 4, 90) // Return True.
	// router.ForwardPacket()     // Return [7, 4, 90].
	// router.ForwardPacket()     // There are no packets left, return [].

	// router := Constructor(4) // Initialize Router with memoryLimit of 2.
	// router.AddPacket(4, 5, 1)
	// router.GetCount(5, 1, 1)

	router := Constructor(2)
	router.AddPacket(3, 1, 3)
	router.AddPacket(1, 2, 3)
	router.AddPacket(4, 5, 3)
	router.GetCount(1, 2, 3)
}

type Pair struct {
	src  int
	des  int
	time int
}

func CPair(s int, d int, t int) Pair {
	return Pair{src: s, des: d, time: t}
}

type Router struct {
	limit      int
	memOrder   map[Pair]int
	order      map[int]Pair
	firstOrder int
	endOrder   int
	desMapTime map[int][]int
	desMapSrc  map[int][]int
}

func Constructor(memoryLimit int) Router {
	return Router{limit: memoryLimit, firstOrder: 0, endOrder: -1, memOrder: make(map[Pair]int), order: make(map[int]Pair), desMapTime: make(map[int][]int), desMapSrc: make(map[int][]int)}
}

func (this *Router) AddPacket(source int, destination int, timestamp int) bool {
	nPair := CPair(source, destination, timestamp)
	if _, ex := this.memOrder[nPair]; ex {
		return false
	}
	this.endOrder++
	this.memOrder[nPair] = this.endOrder
	this.order[this.endOrder] = nPair

	if _, ex := this.desMapTime[destination]; !ex {
		this.desMapTime[destination] = make([]int, 0)
		this.desMapSrc[destination] = make([]int, 0)
	}
	this.desMapTime[destination] = append(this.desMapTime[destination], timestamp)
	this.desMapSrc[destination] = append(this.desMapSrc[destination], source)

	if len(this.order) > this.limit {
		oldestMem := this.order[this.firstOrder]
		delete(this.memOrder, oldestMem)
		delete(this.order, this.firstOrder)
		if _, ex := this.desMapTime[oldestMem.des]; ex {
			if len(this.desMapTime[oldestMem.des]) > 0 && this.desMapTime[oldestMem.des][0] == oldestMem.time && this.desMapSrc[oldestMem.des][0] == oldestMem.src {
				this.desMapTime[oldestMem.des] = this.desMapTime[oldestMem.des][1:]
				this.desMapSrc[oldestMem.des] = this.desMapSrc[oldestMem.des][1:]
			}
		}
		this.firstOrder++
	}
	return true
}

func (this *Router) ForwardPacket() []int {
	if _, ex := this.order[this.firstOrder]; !ex {
		return make([]int, 0)
	}
	oldestMem := this.order[this.firstOrder]
	delete(this.memOrder, oldestMem)
	delete(this.order, this.firstOrder)
	if _, ex := this.desMapTime[oldestMem.des]; ex {
		if len(this.desMapTime[oldestMem.des]) > 0 && this.desMapTime[oldestMem.des][0] == oldestMem.time && this.desMapSrc[oldestMem.des][0] == oldestMem.src {
			this.desMapTime[oldestMem.des] = this.desMapTime[oldestMem.des][1:]
			this.desMapSrc[oldestMem.des] = this.desMapSrc[oldestMem.des][1:]
		}
	}
	this.firstOrder++
	return []int{oldestMem.src, oldestMem.des, oldestMem.time}
}

func (this *Router) GetCount(destination int, startTime int, endTime int) int {
	res := 0
	if val, ex := this.desMapTime[destination]; ex {
		total := getRange(val, startTime, endTime)
		res = len(total)
	}
	return res
}

func getRange(arr []int, start, end int) []int {
	if len(arr) == 0 || start > end {
		return []int{}
	}

	// Find the first index with value >= start
	left := lowerBound(arr, start)

	// Find the first index with value > end, then subtract 1 to get upper index
	right := upperBound(arr, end)

	if left <= right {
		return arr[left : right+1]
	}
	return []int{}
}

func lowerBound(arr []int, target int) int {
	low, high := 0, len(arr)
	for low < high {
		mid := low + (high-low)/2
		if arr[mid] < target {
			low = mid + 1
		} else {
			high = mid
		}
	}
	return low
}

func upperBound(arr []int, target int) int {
	low, high := 0, len(arr)
	for low < high {
		mid := low + (high-low)/2
		if arr[mid] <= target {
			low = mid + 1
		} else {
			high = mid
		}
	}
	return low - 1
}
