#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
#include <queue>
#include <bitset>
using namespace std;

// daily-question&envId=2024-07-04
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
    ListNode *mergeNodes(ListNode *head)
    {
        ListNode *res = new ListNode(0);
        ListNode *tmp = res;
        ListNode *preTmp = nullptr;
        while (head != nullptr)
        {
            tmp->val += head->val;
            head = head->next;
            if (head == nullptr)
                continue;
            if (head->val == 0)
            {
                preTmp = tmp;
                ListNode *next = new ListNode(0);
                tmp->next = next;
                tmp = next;
            }
        }
        preTmp->next = nullptr;
        return res;
    }
};

int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}