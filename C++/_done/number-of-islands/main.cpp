#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>

using namespace std;

vector<vector<char>> stringToGrid(const string& input) {
    vector<vector<char>> grid;
    vector<char> row;

    bool inQuotes = false;
    for (char c : input) {
        if (c == '[') {
            row.clear();
        } else if (isdigit(c)) {
            row.push_back(c);
        } else if (c == ']') {
            if (!row.empty()) {
                grid.push_back(row);
                row.clear();
            }
        }
    }

    return grid;
}

void attackIsland(int m, int n, vector<vector<char>> &grid)
{
    if (m > 0 && grid[m - 1][n] == '1')
    {
        grid[m - 1][n] = '3';
        attackIsland(m - 1, n, grid);
    }
    if (n > 0 && grid[m][n - 1] == '1')
    {
        grid[m][n - 1] = '3';
        attackIsland(m, n - 1, grid);
    }
    if (m < grid.size() - 1 && grid[m + 1][n] == '1')
    {
        grid[m + 1][n] = '3';
        attackIsland(m + 1, n, grid);
    }
    if (n < grid[0].size() - 1 && grid[m][n + 1] == '1')
    {
        grid[m][n + 1] =  '3';
        attackIsland(m, n + 1, grid);
    }
}

int numIslands(vector<vector<char>> &grid)
{
    vector<vector<char>> clonedGrid;
    for (const auto &row : grid)
    {
        vector<char> clonedRow;
        copy(row.begin(), row.end(), back_inserter(clonedRow));
        clonedGrid.push_back(clonedRow);
    }
    int m = grid.size();
    int n = grid[0].size();
    int count = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (clonedGrid[i][j] == '1')
            {
                count++;
                clonedGrid[i][j] = '2';
                attackIsland(i, j, clonedGrid);
            }
        }
    }
    return count;
}
int main()
{
    string input = "[[\"1\",\"1\",\"1\",\"1\",\"0\"],[\"1\",\"1\",\"0\",\"1\",\"0\"],[\"1\",\"1\",\"0\",\"0\",\"0\"],[\"0\",\"0\",\"0\",\"0\",\"0\"]]";
    vector<vector<char>> grid = stringToGrid(input);
    int res = numIslands(grid);
    cout << "hello" << res;
}