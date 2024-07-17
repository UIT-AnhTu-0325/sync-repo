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
    vector<vector<int>> steps = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int m = 0;
    int n = 0;

    int doTravel(int rIdx, int cIdx, vector<vector<int>> &grid, vector<vector<bool>> &traveled)
    {
        if (grid[rIdx][cIdx] == 0)
            return 0;

        int max_gold = 0;

        for (int i = 0; i < 4; i++)
        {
            int movR = rIdx + steps[i][0];
            int movC = cIdx + steps[i][1];

            if (movR < 0 || movR >= m)
                continue;
            if (movC < 0 || movC >= n)
                continue;

            if (traveled[movR][movC])
                continue;

            traveled[movR][movC] = true;

            max_gold = max(max_gold, doTravel(movR, movC, grid, traveled));

            traveled[movR][movC] = false;
        }

        return max_gold + grid[rIdx][cIdx];
    }

    int getMaximumGold(vector<vector<int>> &grid)
    {
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>> traveled = vector<vector<bool>>(m, vector<bool>(n, false));

        int max_gold = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                traveled[i][j] = true;
                max_gold = max(max_gold, doTravel(i, j, grid, traveled));
                traveled[i][j] = false;
            }
        }

        return max_gold;
    }
};

int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}