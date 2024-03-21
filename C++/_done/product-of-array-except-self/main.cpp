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
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> prefixs(n, 1);
        vector<int> suffixs(n, 1);

        for (int i = 1; i < n; i++)
        {
            prefixs[i] = prefixs[i - 1] * nums[i - 1];
        }
        for (int i = n - 2; i >= 0; i--)
        {
            suffixs[i] = suffixs[i + 1] * nums[i + 1];
        }

        vector<int> res;
        for (int i = 0; i < n; i++)
        {
            res.push_back(prefixs[i] * suffixs[i]);
        }
        return res;
    }
};

int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}