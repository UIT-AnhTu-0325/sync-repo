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
    vector<vector<int>> findFarmland(vector<vector<int>> &land)
    {
        vector<vector<int>> ans;
        int m = land.size();
        int n = land[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (land[i][j] == 1)
                {
                    vector<int> ansItem = {i, j, 0, 0};
                    int tmpI = i + 1;
                    while (tmpI < m && land[tmpI][j] == 1)
                    {
                        tmpI++;
                    }
                    int tmpJ = j + 1;
                    while (tmpJ < n && land[i][tmpJ] == 1)
                    {
                        tmpJ++;
                    }
                    ansItem[2] = tmpI - 1;
                    ansItem[3] = tmpJ - 1;
                    for (int x = i; x < tmpI; x++)
                    {
                        for (int y = j; y < tmpJ; y++)
                        {
                            land[x][y] = 3;
                        }
                    }
                    ans.push_back(ansItem);
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