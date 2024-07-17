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
    int singleNumber(vector<int> &nums)
    {
        int ans = 0;

        for (int i = 0; i < 32; ++i)
        {
            int sum = 0;
            for (const int num : nums)
                sum += num >> i & 1;
            sum %= 3;
            ans |= sum << i;
        }

        return ans;
    }
};

int main()
{
    Solution *solution = new Solution();
    vector<int> nums = vector<int>{2, 2, 2, 3};
    int result = solution->singleNumber(nums);
    cout << "Hello world" << result;
}