#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
using namespace std;

class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int k)
    {
        int maxEle = INT32_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            maxEle = max(nums[i], maxEle);
        }

        int left = 0, right = 0;
        long long count = 0;

        while (right < nums.size())
        {
            if (nums[right] == maxEle)
            {
                k--;
            }
            right++;
            while (k == 0)
            {
                if (nums[left] == maxEle)
                {
                    k++;
                }
                left++;
            }
            count += left;
        }
        return count;
    }
};

int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}