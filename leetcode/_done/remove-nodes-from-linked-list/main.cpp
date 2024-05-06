#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
#include <queue>
using namespace std;

// daily-question 2024-05-06
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
    ListNode *removeNodes(ListNode *head)
    {
        ListNode *cur = head;
        stack<ListNode *> stack;

        while (cur != nullptr)
        {
            while (!stack.empty() && stack.top()->val < cur->val)
            {
                stack.pop();
            }
            stack.push(cur);
            cur = cur->next;
        }

        ListNode *nxt = nullptr;
        while (!stack.empty())
        {
            cur = stack.top();
            stack.pop();
            cur->next = nxt;
            nxt = cur;
        }

        return cur;
    }
};

int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}