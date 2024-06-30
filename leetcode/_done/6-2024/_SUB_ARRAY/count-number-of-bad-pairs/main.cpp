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
    long long countBadPairs(vector<int> &nums)
    {
        long long n = nums.size();
        long long res = (n - 1) * n / 2;
        for (int i = 0; i < n; i++)
        {
            nums[i] -= i;
        }
        unordered_map<long long, long long> umap;
        for (int i = 0; i < n; i++)
        {
            if (umap.find(nums[i]) == umap.end())
            {
                umap[nums[i]] = 1;
            }
            else
            {
                umap[nums[i]]++;
            }
        }

        for (pair<long long, long long> p : umap)
        {
            res -= (p.second * (p.second - 1) / 2);
        }

        return res;
    }
};

int main()
{
    vector<int> inp = {4, 1, 3, 3};
    Solution *solution = new Solution();
    solution->countBadPairs(inp);
    cout << "Hello world";
}