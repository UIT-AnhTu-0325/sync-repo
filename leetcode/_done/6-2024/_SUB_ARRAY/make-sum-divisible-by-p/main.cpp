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
    int minSubarray(vector<int> &nums, int p)
    {
        long long n = nums.size();
        vector<long long> calc;
        calc.push_back(0);
        for (long long i = 0; i < nums.size(); i++)
        {
            calc.push_back(calc.back() + (nums[i]));
        }
        int sumMod = calc.back() % p;
        long long res = n;

        if (sumMod == 0)
            return 0;

        unordered_map<long long, long long> umap;
        for (long long i = 0; i < calc.size(); i++)
        {
            long long checkMod = (calc[i] + p - sumMod) % p;
            if (umap.find(checkMod) != umap.end())
            {
                res = min(i - umap[checkMod], res);
            }

            long long mod = calc[i] % p;
            umap[mod] = i;
        }

        if (res == n)
            return -1;

        return res;
    }
};

int main()
{
    vector<int> inp = {1, 2, 3};
    Solution *solution = new Solution();
    solution->minSubarray(inp, 3);
    cout << "Hello world";
}