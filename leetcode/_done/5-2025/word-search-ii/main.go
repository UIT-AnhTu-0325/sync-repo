package main

func main() {
	findWords([][]byte{{'o', 'a', 'a', 'n'}, {'e', 't', 'a', 'e'}, {'i', 'h', 'k', 'r'}, {'i', 'f', 'l', 'v'}}, []string{"oath", "pea", "eat", "rain"})
}

var direction = [][]int{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}

func findWords(board [][]byte, words []string) []string {
	m := len(board)
	n := len(board[0])
	trie := &Trie{child: map[byte]*Trie{}}

	for _, word := range words {
		trie.Insert(word)
	}

	result := []string{}

	var dfs func(i, j int, node *Trie, path []byte)
	dfs = func(i, j int, node *Trie, path []byte) {
		if i < 0 || i >= m || j < 0 || j >= n || board[i][j] == '$' {
			return
		}
		c := board[i][j]
		next, ok := node.child[c]
		if !ok {
			return
		}
		path = append(path, c)
		if next.isEnd {
			result = append(result, string(path))
			next.isEnd = false // Avoid duplicates
		}
		board[i][j] = '$'
		for _, d := range direction {
			dfs(i+d[0], j+d[1], next, path)
		}
		board[i][j] = c
	}

	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			dfs(i, j, trie, []byte{})
		}
	}

	return result
}

type Trie struct {
	child map[byte]*Trie
	isEnd bool
}

func (t *Trie) Insert(word string) {
	node := t
	for i := 0; i < len(word); i++ {
		c := word[i]
		if node.child[c] == nil {
			node.child[c] = &Trie{child: map[byte]*Trie{}}
		}
		node = node.child[c]
	}
	node.isEnd = true
}
