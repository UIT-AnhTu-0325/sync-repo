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
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
    {
        ListNode *left = list1;
        for (int i = 0; i < a - 1; i++)
        {
            left = left->next;
        }

        ListNode *right = left;

        for (int i = 0; i <= b - a + 1; i++)
        {
            right = right->next;
        }

        left->next = list2;
        while (list2->next != nullptr)
        {
            list2 = list2->next;
        }
        list2->next = right;
        return list1;
    }
};
int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}