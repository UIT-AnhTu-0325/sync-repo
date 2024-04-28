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
    int minFallingPathSum(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<vector<int>> build = vector<vector<int>>(n, vector<int>(n, 0));
        for (int i = 1; i < n; i++)
        {
            int MINN = 0;
            int MINNSe = 0;
            for (int j = 0; j < n; j++)
            {
                if (grid[i][MINN] >= grid[i][j])
                {
                    MINNSe = MINN;
                    MINN = j;
                }
            }
            for (int j = 0; j < n; j++)
            {
                if (j == MINN)
                    build[i][j] = grid[i][MINNSe];
                else
                    build[i][j] = grid[i][MINN];
            }
        }

        int res = INT32_MAX;
        for (int j = 0; j < n; j++)
        {
            int sum = 0;
            for (int i = 0; i < n; i++)
            {
                sum += build[i][j];
            }
            res = min(sum, res);
        }
        return res;
    }
};

int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}