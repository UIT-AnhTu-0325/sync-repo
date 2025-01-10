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

        int right = 0, left = 0;
        long long product = 1;
        int sum = 0;
        while (right < nums.size())
        {
            product *= nums[right];

            while (product >= k && left < nums.size())
            {
                product /= nums[left];
                left++;
            }
            sum += (right - left + 1);
            right++;
        }
        return sum;
    }
};

int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}