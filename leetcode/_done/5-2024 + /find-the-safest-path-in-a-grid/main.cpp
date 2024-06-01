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
    int n = 0;
    vector<vector<int>> adjs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void scoring_bfs(vector<vector<int>> &score, vector<vector<int>> &grid)
    {
        queue<pair<int, int>> do_scroring;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    score[i][j] = 0;
                    do_scroring.push({i, j});
                }
            }
        }

        while (!do_scroring.empty())
        {
            pair<int, int> item = do_scroring.front();

            for (int i = 0; i < 4; i++)
            {
                int row = item.first + adjs[i][0];
                int col = item.second + adjs[i][1];

                if (row < 0 || row >= n)
                    continue;
                if (col < 0 || col >= n)
                    continue;

                if (score[row][col] <= score[item.first][item.second] + 1)
                    continue;

                score[row][col] = score[item.first][item.second] + 1;
                do_scroring.push({row, col});
            }

            do_scroring.pop();
        }
    }

    int maximumSafenessFactor(vector<vector<int>> &grid)
    {
        n = grid.size();
        vector<vector<int>> score = vector<vector<int>>(n, vector<int>(n, INT32_MAX - 1));

        scoring_bfs(score, grid);
        //bfs(grid, score, n);

        vector<vector<bool>> visited = vector<vector<bool>>(n, vector<bool>(n, false));

        priority_queue<pair<int, pair<int, int>>> travel;
        travel.push({score[0][0], {0, 0}});

        while (!travel.empty())
        {
            int min_score = travel.top().first;
            pair<int, int> idxs = travel.top().second;

            if (idxs.first == n - 1 && idxs.second == n - 1)
                return min_score;
            travel.pop();

            visited[idxs.first][idxs.second] = true;

            for (int i = 0; i < 4; i++)
            {
                int row = idxs.first + adjs[i][0];
                int col = idxs.second + adjs[i][1];

                if (row < 0 || row >= n)
                    continue;
                if (col < 0 || col >= n)
                    continue;
                if (visited[row][col])
                    continue;

                int crrMin = min(min_score, score[row][col]);
                visited[row][col] = true;
                travel.push({crrMin, {row, col}});
            }
        }

        return -1;
    }
};

int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}