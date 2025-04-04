#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
#include <queue>
using namespace std;

// daily-question 2024-06-22
class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        int l = 0, r = 0, l2 = -1;
        int crr = 0;
        int res = 0;
        while (r < nums.size())
        {
            if (nums[r] % 2 != 0)
                crr++;
            while (crr > k)
            {
                if (nums[l] % 2 != 0)
                {
                    crr--;
                }
                l++;
                l2 = -1;
            }
            if (crr == k)
            {
                if (l2 == -1)
                {
                    l2 = l;
                    while (nums[l2] % 2 == 0)
                    {
                        l2++;
                    }
                }

                res += (l2 - l + 1);
            }
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