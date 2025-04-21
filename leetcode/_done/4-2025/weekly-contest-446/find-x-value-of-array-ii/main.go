package main

func main() {
	resultArray([]int{1, 2, 3, 4, 5}, 3, [][]int{{2, 2, 0, 2}, {3, 3, 3, 0}, {0, 1, 0, 1}})
}

const MAXK = 5

type node struct {
	prod int
	cnt  [MAXK]int
	k    int
}

func newNode(k int) node {
	n := node{k: k}
	n.prod = 1 % max(1, k)
	return n
}

type SegmentTree struct {
	n, k, size int
	seg        []node
}

func NewSegmentTree(a []int, k int) *SegmentTree {
	n := len(a)
	size := 1
	for size < n {
		size <<= 1
	}
	seg := make([]node, 2*size)
	st := &SegmentTree{n, k, size, seg}

	for i := 0; i < n; i++ {
		v := a[i] % k
		nd := newNode(k)
		nd.prod = v
		nd.cnt[v] = 1
		st.seg[size+i] = nd
	}
	for p := size - 1; p > 0; p-- {
		st.seg[p] = st.merge(st.seg[2*p], st.seg[2*p+1])
	}
	return st
}

func (st *SegmentTree) merge(L, R node) node {
	res := newNode(st.k)
	res.prod = (L.prod * R.prod) % st.k
	for r := 0; r < st.k; r++ {
		res.cnt[r] = L.cnt[r]
	}
	for r2 := 0; r2 < st.k; r2++ {
		c := R.cnt[r2]
		if c > 0 {
			r := (L.prod * r2) % st.k
			res.cnt[r] += c
		}
	}
	return res
}

func (st *SegmentTree) Update(idx, vmod int) {
	p := st.size + idx
	nd := newNode(st.k)
	nd.prod = vmod
	nd.cnt[vmod] = 1
	st.seg[p] = nd
	for p >>= 1; p > 0; p >>= 1 {
		st.seg[p] = st.merge(st.seg[2*p], st.seg[2*p+1])
	}
}

func (st *SegmentTree) Query(l, r int) node {
	resL := newNode(st.k)
	resR := newNode(st.k)
	for l, r = l+st.size, r+st.size; l <= r; l, r = (l+1)>>1, (r-1)>>1 {
		if l&1 == 1 {
			resL = st.merge(resL, st.seg[l])
			l++
		}
		if r&1 == 0 {
			resR = st.merge(st.seg[r], resR)
			r--
		}
	}
	return st.merge(resL, resR)
}

func resultArray(nums []int, k int, queries [][]int) []int {
	st := NewSegmentTree(nums, k)
	ans := make([]int, len(queries))
	for i, q := range queries {
		idx, val, left, wantMod := q[0], q[1]%k, q[2], q[3]
		st.Update(idx, val)
		nd := st.Query(left, len(nums)-1)
		ans[i] = nd.cnt[wantMod]
	}
	return ans
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
