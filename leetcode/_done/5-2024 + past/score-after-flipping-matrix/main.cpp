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
    int matrixScore(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        int sum = 0;

        for (int i = 0; i < m; i++)
        {
            if (grid[i][0] == 0)
            {
                for (int j = 0; j < n; j++)
                {
                    grid[i][j] = abs(grid[i][j] - 1);
                }
            }
        }

        sum += pow(2, n - 1) * m;

        for (int j = 1; j < n; j++)
        {
            int countOne = 0;
            for (int i = 0; i < m; i++)
            {
                if (grid[i][j] == 1)
                    countOne++;
            }
            int countZero = n - countOne;
            int multiple = max(countOne, countZero);
            sum += pow(2, n - j - 1) * multiple;
        }

        return sum;
    }
};

int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}