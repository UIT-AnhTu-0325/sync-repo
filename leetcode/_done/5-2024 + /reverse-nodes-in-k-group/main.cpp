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
    // O(1) space solution
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *ans = nullptr;
        ListNode *build = nullptr;
        ListNode *startBuild = head;
        ListNode *crrBuild = nullptr;

        int count = 0;
        while (count < k && head != nullptr)
        {

            ListNode *tmp = head->next;
            head->next = crrBuild;
            crrBuild = head;
            head = tmp;

            count++;

            if (count == k)
            {
                if (ans == nullptr)
                {
                    ans = crrBuild;
                    build = crrBuild;
                }
                else
                {
                    build->next = crrBuild;
                }
                while(build->next != nullptr){
                    build = build->next;
                }
                startBuild = head;
                count = 0;
                crrBuild = nullptr;
            }
        }

        ListNode* reverted = nullptr;
        while(crrBuild != nullptr){
            ListNode * tmp = crrBuild->next;
            crrBuild->next = reverted;
            reverted = crrBuild;
            crrBuild = tmp;
        }

        build->next = reverted;

        return ans;
    }
};

int main()
{
    Solution *solution = new Solution();
    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    solution->reverseKGroup(head, 3);
    cout << "Hello world";
}

// O(n) space solution
// ListNode *reverseKGroup_byOn(ListNode *head, int k)
// {
//     ListNode *ans = nullptr;
//     ListNode *build = nullptr;
//     ListNode *startBuild = head;

//     stack<ListNode *> stak;
//     while (stak.size() < k && head != nullptr)
//     {
//         stak.push(head);
//         head = head->next;
//         if (stak.size() == k)
//         {
//             startBuild = head;
//             while (!stak.empty())
//             {
//                 if (ans == nullptr)
//                 {
//                     ans = stak.top();
//                     build = stak.top();
//                 }
//                 else
//                 {
//                     build->next = stak.top();
//                     build = build->next;
//                 }
//                 stak.pop();
//             }
//         }
//     }
//     build->next = startBuild;
//     return ans;
// }