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
    long long countInterestingSubarrays(vector<long long> &nums, long long modulo, long long k)
    {
        long long n = nums.size();
        vector<long long> calc = {0};

        for (long long i = 0; i < nums.size(); i++)
        {
            calc.push_back(calc.back() + ((nums[i] % modulo == k) ? 1 : 0));
        }

        unordered_map<long long, long long> umap;
        long long res = 0;
        for (long long i = 0; i < calc.size(); i++)
        {
            long long mod = (calc[i] + modulo - k) % modulo;
            long long crrMod = calc[i] % modulo;
            if (umap.find(mod) != umap.end())
            {
                res += umap[mod];
            }
            if (umap.find(crrMod) != umap.end())
            {
                umap[crrMod]++;
            }
            else
            {
                umap[crrMod] = 1;
            }
        }
        return res;
    }
};

long long main()
{
    vector<long long> inp = {5, 1};
    Solution *solution = new Solution();
    solution->countInterestingSubarrays(inp, 6, 1);
    cout << "Hello world";
}