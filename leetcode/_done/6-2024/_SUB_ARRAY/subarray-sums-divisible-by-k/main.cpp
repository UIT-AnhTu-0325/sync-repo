#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
#include <queue>
using namespace std;

// daily-question 2024-06-09
class Solution
{
public:
    int subarraysDivByK(vector<int> nums, int k)
    {
        int n = nums.size();
        vector<int> calc = {0};

        for (int i = 0; i < nums.size(); i++)
        {
            calc.push_back(calc.back() + nums[i]);
        }

        int res = 0;

        unordered_map<int, int> mod;
        for (int i = 0; i <= n; i++)
        {
            int iMode = calc[i] % k;
            if (iMode < 0)
                iMode += k;
            if (mod.find(iMode) == mod.end())
                mod[iMode] = 1;
            else
                mod[iMode]++;
        }

        for (pair<int, int> p : mod)
        {
            res += (p.second * (p.second - 1) / 2);
        }

        return res;
    }
};

int main()
{
    Solution *solution = new Solution();
    vector<int> inp = {7, -5, 5, -8, -6, 6, -4, 7, -8, -7};
    solution->subarraysDivByK(inp, 7);
    cout << "Hello world";
}