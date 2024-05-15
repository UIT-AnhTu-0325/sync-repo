#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

int minSubArrayLen(int target, vector<int> &nums)
{
    const int n = nums.size();
    int minLen = INT_MAX;
    for (int l = 0, r = 0, sum = 0; r < n; r++)
    {
        sum += nums[r];
        while (sum >= target)
        {
            minLen = min(minLen, r - l + 1);
            sum -= nums[l];
            l++;
        }
    }
    if (minLen == INT_MAX)
        return 0;
    return minLen;
}

int main()
{
}