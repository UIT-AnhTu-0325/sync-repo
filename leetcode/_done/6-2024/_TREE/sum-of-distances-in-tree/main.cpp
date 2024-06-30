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
    vector<vector<int>> adj;
    int inpN;

    void dfs(int node, int prev, vector<int> &height, vector<int> &subtree)
    {
        subtree[node]++;
        for (auto &ele : adj[node])
        {
            if (ele != prev)
            {
                height[ele] = 1 + height[node];
                dfs(ele, node, height, subtree);
                subtree[node] += subtree[ele];
            }
        }
    }
    void rec(int node, int prev, vector<int> &subtree, vector<int> &dp)
    {
        for (auto &ele : adj[node])
        {
            if (ele != prev)
            {
                dp[ele] = dp[node] - subtree[ele] + (inpN - subtree[ele]);
                rec(ele, node, subtree, dp);
            }
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges)
    {
        inpN = n;
        adj = vector<vector<int>>(n, vector<int>());
        for (auto &ele : edges)
        {
            int u = ele[0], v = ele[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> height(n, 0), subtree(n, 0); // distance from 0 to all other nodes;
        vector<int> dp(n, 0);                    // dp[i] = sum of distances from node i to all other nodes;
        dfs(0, -1, height, subtree);
        for (int i = 0; i < n; i++)
            dp[0] += height[i];
        rec(0, -1, subtree, dp);
        return dp;
    }
};

int main()
{
    vector<vector<int>> vec = {
        {0, 1},
        {0, 2},
        {2, 3},
        {2, 4},
        {2, 5}};
    Solution *solution = new Solution();
    solution->sumOfDistancesInTree(6, vec);
    cout << "Hello world";
}