package main

type Node struct {
	key, val   int
	prev, next *Node
}

type LRUCache struct {
	capacity   int
	cache      map[int]*Node
	head, tail *Node
}

func Constructor(capacity int) LRUCache {
	lru := LRUCache{
		capacity: capacity,
		cache:    make(map[int]*Node),
		head:     &Node{},
		tail:     &Node{},
	}
	lru.head.next = lru.tail
	lru.tail.prev = lru.head
	return lru
}

func (lru *LRUCache) moveToFront(node *Node) {
	lru.removeNode(node)
	lru.addToFront(node)
}

func (lru *LRUCache) addToFront(node *Node) {
	node.next = lru.head.next
	node.prev = lru.head
	lru.head.next.prev = node
	lru.head.next = node
}

func (lru *LRUCache) removeNode(node *Node) {
	node.prev.next = node.next
	node.next.prev = node.prev
}

func (lru *LRUCache) Get(key int) int {
	if node, found := lru.cache[key]; found {
		lru.moveToFront(node)
		return node.val
	}
	return -1
}

func (lru *LRUCache) Put(key int, value int) {
	if node, found := lru.cache[key]; found {
		node.val = value
		lru.moveToFront(node)
		return
	}

	if len(lru.cache) == lru.capacity {
		lruKey := lru.tail.prev.key
		lru.removeNode(lru.tail.prev)
		delete(lru.cache, lruKey)
	}

	newNode := &Node{key: key, val: value}
	lru.cache[key] = newNode
	lru.addToFront(newNode)
}
