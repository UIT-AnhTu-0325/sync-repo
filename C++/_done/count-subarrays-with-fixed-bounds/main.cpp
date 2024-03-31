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
    long long countSubarrays(vector<int> &nums, int minK, int maxK)
    {
        nums = vector<int>{1, 3, 5, 2, 7, 5};
        minK = 1;
        maxK = 5;

        int left = 0, right = 0;
        int posMin = -1, posMax = -1;
        long long ans = 0;

        while (right < nums.size())
        {
            if (maxK < nums[right] || minK > nums[right])
            {
                left = right + 1;
                right++;
                continue;
            }
            if (nums[right] == minK)
            {
                posMin = right;
            }
            if (nums[right] == maxK)
            {
                posMax = right;
            }

            if (posMin >= left && posMax >= left)
            {
                ans += (min(posMax, posMin) - left + 1);
            }

            right++;
        }

        return ans;
    }
};

int main()
{
    Solution *solution = new Solution();
    vector<int> a;
    solution->countSubarrays(a, 1, 2);
    cout << "Hello world";
}