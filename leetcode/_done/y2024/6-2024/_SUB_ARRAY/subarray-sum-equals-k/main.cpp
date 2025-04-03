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
    int subarraySum(vector<int> &nums, int k)
    {
        vector<int> calc = {0};
        for (int i = 0; i < nums.size(); i++)
        {
            calc.push_back(calc.back() + nums[i]);
        }
        int res = 0;
        unordered_map<int, int> umap;
        for (int i = 0; i < calc.size(); i++)
        {
            if (umap.find(calc[i] - k) != umap.end())
            {
                res += umap[calc[i] - k];
            }
            if (umap.find(calc[i]) == umap.end())
            {
                umap[calc[i]] = 1;
            }
            else
            {
                umap[calc[i]]++;
            }
        }
        return res;
    }
};

int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}