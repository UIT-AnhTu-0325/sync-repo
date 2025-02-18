#include <algorithm>
#include <bitset>
#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// daily-question 2024-07-21
class Solution
{
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>> &rowConditions,
                                    vector<vector<int>> &colConditions)
    {
        vector<int> orderRow = getOrder(rowConditions, k);
        vector<int> orderCol = getOrder(colConditions, k);

        if (orderRow.size() == 0 || orderCol.size() == 0)
            return {};
        vector<vector<int>> res = vector<vector<int>>(k, vector<int>(k, 0));
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < k; j++)
            {
                if (orderRow[i] == orderCol[j])
                    res[i][j] = orderRow[i];
            }
        }
        return res;
    }

private:
    vector<int> getOrder(vector<vector<int>> src, int k)
    {
        vector<vector<int>> adj(k + 1);
        // 0 => not visit, 1 => visiting, 2 => visited
        vector<int> visited(k + 1, 0);
        bool hasCycle = false;
        vector<int> order;

        for (int i = 0; i < src.size(); i++)
        {
            adj[src[i][0]].push_back(src[i][1]);
        }

        // Perform DFS for each node
        for (int i = 1; i <= k; i++)
        {
            if (visited[i] == 0)
            {
                dfs(i, adj, visited, order, hasCycle);
                // Return empty if cycle detected
                if (hasCycle)
                    return {};
            }
        }
        // Reverse to get the correct order
        reverse(order.begin(), order.end());
        return order;
    }

    void dfs(int node, vector<vector<int>> &adj, vector<int> &visited,
             vector<int> &order, bool &hasCycle)
    {
        visited[node] = 1; // Mark node as visiting
        for (int neighbor : adj[node])
        {
            if (visited[neighbor] == 0)
            {
                dfs(neighbor, adj, visited, order, hasCycle);
                // Early exit if a cycle is detected
                if (hasCycle)
                    return;
            }
            else if (visited[neighbor] == 1)
            {
                // Cycle detected
                hasCycle = true;
                return;
            }
        }
        // Mark node as visited
        visited[node] = 2;
        // Add node to the order
        order.push_back(node);
    }
};

int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}