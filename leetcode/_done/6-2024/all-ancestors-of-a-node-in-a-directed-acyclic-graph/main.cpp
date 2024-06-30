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
    void dfs(vector<vector<int>> relate, int parrent, int crr, vector<vector<int>> &res, vector<bool> visit)
    {
        visit[crr] = true;
        for (int i = 0; i < relate[crr].size(); i++)
        {
            int child = relate[crr][i];
            if (!visit[child])
            {
            }
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> res = vector<vector<int>>(n, vector<int>());
        vector<vector<int>> relate = vector<vector<int>>(n, vector<int>());
        vector<bool> hasChild = vector<bool>(n, false);

        for (vector<int> edge : edges)
        {
            relate[edge[0]].push_back(edge[1]);
            hasChild[edge[1]] = true;
        }
        queue<pair<int, int>> build;
        for (int i = 0; i < n; i++)
        {
            if (!hasChild[i])
                build.push({-1, i});
        }

        return res;
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