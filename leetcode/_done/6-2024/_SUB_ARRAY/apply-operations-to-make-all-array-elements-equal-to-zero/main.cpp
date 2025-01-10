#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
#include <queue>
using namespace std;

class Solution
{
public:
    bool checkArray(vector<int> nums, int k)
    {
        int n = nums.size();
        vector<int> mp(n + 1, 0);
        int curr = 0;
        for (int i = 0; i < n; i++)
        {
            curr -= mp[i];
            nums[i] -= curr;
            if (nums[i] < 0)
            {
                return false;
            }
            else if (nums[i] > 0)
            {
                if (i + k > n)
                {
                    return false;
                }
                mp[i + k] += nums[i];

                curr += nums[i];
            }
        }
        return true;
    }
};

int main()
{
    Solution *solution = new Solution();
    vector<int> inp = {2, 2, 3, 1, 1, 0};
    solution->checkArray(inp, 3);
    cout << "Hello world";
}