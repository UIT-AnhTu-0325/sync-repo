#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
#include <queue>
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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == nullptr)
            return list2;
        if (list2 == nullptr)
            return list1;

        ListNode *ans = list1;
        if (list1->val > list2->val)
        {
            ans = list2;
            list2 = list2->next;
        }
        else
        {
            list1 = list1->next;
        }
        ListNode *cur = ans;
        while (list1 != nullptr && list2 != nullptr)
        {
            bool is1Low = list1->val < list2->val;
            cur->next = is1Low ? list1 : list2;
            is1Low ? list1 = list1->next : list2 = list2->next;
            cur = cur->next;
        }

        if (list1 == nullptr)
        {
            cur->next = list2;
        }
        else
        {
            cur->next = list1;
        }

        return ans;
    }
};

int main()
{
    Solution *solution = new Solution();
    solution->mergeTwoLists(NULL, NULL);
    cout << "Hello world";
}