#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
#include <queue>
using namespace std;

// daily-question 2024-06-23
class Solution
{
public:
    int longestSubarray(vector<int> &nums, int limit)
    {
        int l = 0, r = 0, cMax = nums[0], cMin = nums[0];
        int res = 0;
        while (r < nums.size())
        {
            cMax = max(nums[r], cMax);
            cMin = min(nums[r], cMin);

            if (abs(cMax - cMin) > limit)
            {
                l = r;
                int tmp = nums[l];
                if (cMax == nums[r])
                {
                    while (cMax - nums[l] <= limit && l >= 0)
                    {
                        tmp = min(nums[l], tmp);
                        l--;
                    }
                    if (l < 0)
                    {
                        l = r;
                        cMin = nums[r];
                        cMax = cMin;
                    }
                    else
                    {
                        cMin = tmp;
                        l++;
                    }
                }
                else
                {
                    while (nums[l] - cMin <= limit && l >= 0)
                    {
                        tmp = max(nums[l], tmp);
                        l--;
                    }
                    if (l < 0)
                    {
                        l = r;
                        cMin = nums[r];
                        cMax = cMin;
                    }
                    else
                    {
                        cMax = tmp;
                        l++;
                    }
                }
            }

            res = max(res, r - l + 1);

            r++;
        }
        return res;
    }
};

int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}