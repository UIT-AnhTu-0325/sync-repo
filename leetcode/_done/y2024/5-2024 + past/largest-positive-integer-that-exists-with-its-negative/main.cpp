#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
#include <queue>
using namespace std;

// daily-question 2024-05-02
class Solution
{
public:
    int findMaxK(vector<int> &nums)
    {
        unordered_map<int, int> builder;

        int ans = INT32_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            if (abs(nums[i]) > ans)
            {
                if (builder.find(-1 * nums[i]) != builder.end())
                {
                    ans = abs(nums[i]);
                }
            }

            builder[nums[i]] = i;
        }

        return ans == INT32_MIN ? -1 : ans;
    }
};

int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}