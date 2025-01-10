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
    int islandPerimeter(vector<vector<int>> &grid)
    {
        vector<int> tmpR = {0, 1, -1, 0};
        vector<int> tmpC = {1, 0, 0, -1};

        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    for (int k = 0; k < 4; k++)
                    {
                        int crrR = i + tmpR[k];
                        int crrC = j + tmpC[k];
                        if (crrR < 0 || crrR >= m)
                        {
                            ans += 1;
                        }
                        else if (crrC < 0 || crrC >= n)
                        {
                            ans += 1;
                        }
                        else if (grid[crrR][crrC] == 0)
                        {
                            ans += 1;
                        }
                    }
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}