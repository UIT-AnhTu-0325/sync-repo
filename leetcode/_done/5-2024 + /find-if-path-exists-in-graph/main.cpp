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
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        if (source == destination)
            return true;
        queue<int> solve;
        for (int i = 0; i < edges.size(); i++)
        {
            if (edges[i][0] == source)
            {
                solve.push(edges[i][1]);
                edges.erase(edges.begin() + i);
                i--;
            }
            else if (edges[i][1] == source)
            {
                solve.push(edges[i][0]);
                edges.erase(edges.begin() + i);
                i--;
            }
        }
        while (!solve.empty())
        {
            if (solve.front() == destination)
            {
                return true;
            }
            for (int i = 0; i < edges.size(); i++)
            {
                if (edges[i][0] == solve.front())
                {
                    solve.push(edges[i][1]);
                    edges.erase(edges.begin() + i);
                    i--;
                }
                else if (edges[i][1] == solve.front())
                {
                    solve.push(edges[i][0]);
                    edges.erase(edges.begin() + i);
                    i--;
                }
            }
            solve.pop();
        }
        return false;
    }
};

int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}