#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
#include <queue>
using namespace std;

// daily-question 2024-06-28
class Solution
{
public:
    long long maximumImportance(int n, vector<vector<int>> &roads)
    {
        unordered_map<long long, long long> umap;
        for (long long i = 0; i < roads.size(); i++)
        {
            for (long long j = 0; j <= 1; j++)
            {
                if (umap.find(roads[i][j]) == umap.end())
                    umap[roads[i][j]] = 1;
                else
                    umap[roads[i][j]]++;
            }
        }
        vector<long long> edgeTime;
        for (pair<long long, long long> p : umap)
        {
            edgeTime.push_back(p.second);
        }
        sort(edgeTime.begin(), edgeTime.end());
        long long crr = n, res = 0;
        for (long long i = edgeTime.size() - 1; i >= 0; i--)
        {
            res += edgeTime[i] * crr;
            crr--;
        }
        return res;
    }
};

long long main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}