#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
#include <queue>
using namespace std;

// daily-question 2024-05-07
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    int calc(ListNode *head)
    {
        if (head == nullptr)
            return 0;
        int mem = calc(head->next);
        head->val = head->val * 2 + mem;
        int memback = head->val >= 10 ? 1 : 0;
        head->val = head->val % 10;
        return memback;
    }
    ListNode *doubleIt(ListNode *head)
    {
        int mem = calc(head);
        if (mem == 0)
            return head;
        else
            return new ListNode(mem, head);
    }
};

int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}