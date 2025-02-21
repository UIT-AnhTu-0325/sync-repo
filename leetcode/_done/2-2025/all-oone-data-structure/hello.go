package main

import (
	"container/list"
)

type Node struct {
	freq    int
	strSet  map[string]struct{}
	element *list.Element
}

type AllOne struct {
	dll          *list.List
	strToNodeMap map[string]*Node
}

func Constructor() AllOne {
	return AllOne{
		dll:          list.New(),
		strToNodeMap: make(map[string]*Node),
	}
}

func (this *AllOne) Inc(key string) {
	if node, exists := this.strToNodeMap[key]; exists {
		freq := node.freq
		delete(node.strSet, key)

		var nextNode *Node
		if node.element.Next() != nil {
			nextNode = node.element.Next().Value.(*Node)
		}

		if nextNode == nil || nextNode.freq != freq+1 {
			newNode := &Node{
				freq:    freq + 1,
				strSet:  make(map[string]struct{}),
				element: this.dll.InsertAfter(nil, node.element),
			}
			newNode.strSet[key] = struct{}{}
			newNode.element.Value = newNode
			this.strToNodeMap[key] = newNode
		} else {
			nextNode.strSet[key] = struct{}{}
			this.strToNodeMap[key] = nextNode
		}

		if len(node.strSet) == 0 {
			this.dll.Remove(node.element)
		}
	} else {
		var firstNode *Node
		if this.dll.Len() > 0 {
			firstNode = this.dll.Front().Value.(*Node)
		}

		if firstNode == nil || firstNode.freq > 1 {
			newNode := &Node{
				freq:    1,
				strSet:  make(map[string]struct{}),
				element: this.dll.PushFront(nil),
			}
			newNode.strSet[key] = struct{}{}
			newNode.element.Value = newNode
			this.strToNodeMap[key] = newNode
		} else {
			firstNode.strSet[key] = struct{}{}
			this.strToNodeMap[key] = firstNode
		}
	}
}

func (this *AllOne) Dec(key string) {
	if node, exists := this.strToNodeMap[key]; exists {
		delete(node.strSet, key)
		freq := node.freq

		if freq == 1 {
			delete(this.strToNodeMap, key)
		} else {
			var prevNode *Node
			if node.element.Prev() != nil {
				prevNode = node.element.Prev().Value.(*Node)
			}

			if prevNode == nil || prevNode.freq != freq-1 {
				newNode := &Node{
					freq:    freq - 1,
					strSet:  make(map[string]struct{}),
					element: this.dll.InsertBefore(nil, node.element),
				}
				newNode.strSet[key] = struct{}{}
				newNode.element.Value = newNode
				this.strToNodeMap[key] = newNode
			} else {
				prevNode.strSet[key] = struct{}{}
				this.strToNodeMap[key] = prevNode
			}
		}

		if len(node.strSet) == 0 {
			this.dll.Remove(node.element)
		}
	}
}

func (this *AllOne) GetMaxKey() string {
	if this.dll.Len() == 0 {
		return ""
	}
	lastNode := this.dll.Back().Value.(*Node)
	for k := range lastNode.strSet {
		return k
	}
	return ""
}

func (this *AllOne) GetMinKey() string {
	if this.dll.Len() == 0 {
		return ""
	}
	firstNode := this.dll.Front().Value.(*Node)
	for k := range firstNode.strSet {
		return k
	}
	return ""
}

func main() {
}
