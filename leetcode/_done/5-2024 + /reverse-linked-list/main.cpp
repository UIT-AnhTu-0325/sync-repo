#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
using namespace std;

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
    ListNode *reverseList(ListNode *head)
    {
        ListNode* ptr = nullptr;
        while(head != nullptr)
        {
            ListNode* tail = new ListNode(head->val);
            tail->next = ptr;
            ptr = tail;
            head = head->next;
        }
        return ptr;
    }
};

int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}