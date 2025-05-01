package main

func main() {
	obj := Constructor()
	obj.AddWord("bad")
	obj.Search("b..")
}

type WordDictionary struct {
	child map[byte]*WordDictionary
	isEnd bool
}

func Constructor() WordDictionary {
	return WordDictionary{
		child: make(map[byte]*WordDictionary),
		isEnd: false,
	}
}

func (this *WordDictionary) AddWord(word string) {
	root := this
	for i := range word {
		if _, ex := root.child[word[i]]; !ex {
			newDic := Constructor()
			root.child[word[i]] = &newDic
		}
		if i == len(word)-1 {
			root.child[word[i]].isEnd = true
		}
		root = root.child[word[i]]
	}
}

func (this *WordDictionary) Search(word string) bool {
	return SearchByte(word, 0, this)
}

func SearchByte(word string, idx int, dic *WordDictionary) bool {
	if idx >= len(word) {
		return false
	}
	if val, ex := dic.child[word[idx]]; ex {
		if idx == len(word)-1 {
			if val.isEnd {
				return true
			} else {
				return false
			}
		} else {
			return SearchByte(word, idx+1, dic.child[word[idx]])
		}
	} else if word[idx] == '.' {
		if idx == len(word)-1 {
			for i := range dic.child {
				if dic.child[i].isEnd {
					return true
				}
			}
			return false
		}
		res := false
		for i := range dic.child {
			res = SearchByte(word, idx+1, dic.child[i]) || res
		}
		return res
	} else {
		return false
	}
}
