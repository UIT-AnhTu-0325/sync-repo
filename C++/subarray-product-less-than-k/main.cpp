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
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        if (k <= 1)
            return 0;
        unsigned long long prod = 1;
        int n = nums.size(), l = 0, cnt = 0;
        for (int r = 0; r < n; r++)
        {
            prod *= nums[r];
            while (prod >= k)
            {
                prod /= nums[l];
                l++;
            }
            cnt += (r - l + 1);
        }
        return cnt;
    }
};

int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}