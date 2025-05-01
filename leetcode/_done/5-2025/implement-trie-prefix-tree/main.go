package main

func main() {
	// obj := Constructor()
	// obj.Insert(word)
	// param_2 := obj.Search(word)
	// param_3 := obj.StartsWith(prefix)
}

type Trie struct {
	child map[byte]*Trie
	isEnd bool
}

func Constructor() Trie {
	return Trie{
		child: make(map[byte]*Trie),
		isEnd: false,
	}
}

func (this *Trie) Insert(word string) {
	rootTrie := this.child
	for i := range word {
		if _, ex := rootTrie[word[i]]; !ex {
			newTree := Constructor()
			rootTrie[word[i]] = &newTree
		}
		if i == len(word)-1 {
			rootTrie[word[i]].isEnd = true
		}
		rootTrie = rootTrie[word[i]].child
	}
}

func (this *Trie) Search(word string) bool {
	rootTrie := this.child
	isEnd := false
	for i := range word {
		if _, ex := rootTrie[word[i]]; !ex {
			return false
		}
		isEnd = rootTrie[word[i]].isEnd
		rootTrie = rootTrie[word[i]].child
	}
	return isEnd
}

func (this *Trie) StartsWith(prefix string) bool {
	rootTrie := this.child
	for i := range prefix {
		if _, ex := rootTrie[prefix[i]]; !ex {
			return false
		}
		rootTrie = rootTrie[prefix[i]].child
	}
	return true
}
