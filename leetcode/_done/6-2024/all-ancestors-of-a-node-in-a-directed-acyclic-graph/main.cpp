#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
#include <queue>
using namespace std;

// daily-question 2024-06-29
class Solution
{
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> res(n);
        vector<vector<int>> graph(n);

        for (const auto &edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
        }

        for (int i = 0; i < n; ++i)
        {
            vector<bool> visit(n, false);
            dfs(graph, i, i, res, visit);
        }

        for (int i = 0; i < n; ++i)
        {
            sort(res[i].begin(), res[i].end());
        }

        return res;
    }

private:
    void dfs(vector<vector<int>> &graph, int parent, int curr, vector<vector<int>> &res, vector<bool> &visit)
    {
        visit[curr] = true;
        for (int dest : graph[curr])
        {
            if (!visit[dest])
            {
                res[dest].push_back(parent);
                dfs(graph, parent, dest, res, visit);
            }
        }
    }
};

int main()
{
    vector<vector<int>> data = {
        {0, 3},
        {0, 4},
        {1, 3},
        {2, 4},
        {2, 7},
        {3, 5},
        {3, 6},
        {3, 7},
        {4, 6}};
    Solution *solution = new Solution();
    solution->getAncestors(8, data);
    cout << "Hello world";
}