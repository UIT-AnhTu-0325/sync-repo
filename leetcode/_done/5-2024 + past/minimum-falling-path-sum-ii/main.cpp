#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
#include <queue>
using namespace std;

struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2> &p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

class Solution
{
public:
    int n;
    unordered_map<pair<int, int>, int, pair_hash> solved;

    int solve(vector<vector<int>> &grid, int crrI, int preJ)
    {
        if (crrI == n - 1)
        {
            int ans = INT32_MAX;
            for (int j = 0; j < n; j++)
            {
                if (j == preJ)
                    continue;
                ans = min(grid[crrI][j], ans);
            }
            return ans;
        }

        int mValue = INT32_MAX;
        for (int j = 0; j < n; j++)
        {
            int crrValue;

            if (j == preJ)
                continue;
            if (solved.find(make_pair(crrI, j)) != solved.end())
            {
                crrValue = solved[make_pair(crrI, j)];
            }
            else
            {
                crrValue = solve(grid, crrI + 1, j) + grid[crrI][j];
                solved[make_pair(crrI, j)] = crrValue;
            }

            mValue = min(mValue, crrValue);
        }

        return mValue;
    }
    int minFallingPathSum(vector<vector<int>> &grid)
    {
        n = grid.size();
        return solve(grid, 0, -1);
    }
};

// Better solution
// We can store the solve in the matrix like grid, no need to use map with hash
class Solution2
{
public:
    int minFallingPathSum(vector<vector<int>> &grid)
    {
        int n = grid.size(), res = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(n, -1));

        for (int j = 0; j < n; ++j)
        {
            dp[0][j] = grid[0][j];
        }

        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                int temp = INT_MAX;

                for (int k = 0; k < n; ++k)
                {
                    if (k != j)
                    {
                        temp = min(temp, grid[i][j] + dp[i - 1][k]);
                    }

                    dp[i][j] = temp;
                }
            }
        }

        for (int j = 0; j < n; ++j)
        {
            res = min(res, dp[n - 1][j]);
        }

        return res;
    }
};

int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}