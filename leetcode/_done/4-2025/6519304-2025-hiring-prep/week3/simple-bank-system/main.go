package main

type Bank struct {
	balance []int64
	n       int
}

func Constructor(balance []int64) Bank {
	n := len(balance)
	return Bank{balance: balance, n: n}
}

func (this *Bank) Transfer(account1 int, account2 int, money int64) bool {
	if account1 > this.n || account2 > this.n {
		return false
	}
	if this.balance[account1-1] < money {
		return false
	}
	this.balance[account1-1] -= money
	this.balance[account2-1] += money
	return true
}

func (this *Bank) Deposit(account int, money int64) bool {
	if account > this.n {
		return false
	}
	this.balance[account-1] += money
	return true
}

func (this *Bank) Withdraw(account int, money int64) bool {
	if account > this.n {
		return false
	}
	if this.balance[account-1] < money {
		return false
	}
	this.balance[account-1] -= money
	return true
}

func main() {
}
