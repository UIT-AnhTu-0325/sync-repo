#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
#include <queue>
using namespace std;

// i don't trust myself anymore

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        heights.push_back(0);
        stack<int> incr;
        int ans = 0;
        for (int i = 0; i < heights.size(); i++)
        {
            if (incr.empty() || heights[i] >= heights[incr.top()])
            {
                incr.push(i);
            }
            else
            {
                while (!incr.empty() && heights[i] < heights[incr.top()])
                {
                    int top = incr.top();
                    incr.pop();
                    int leftSmall = -1;
                    if (!incr.empty())
                    {
                        leftSmall = incr.top();
                    }
                    int rightSmall = i;
                    ans = max(ans, heights[top] * (rightSmall - leftSmall - 1));
                }
                incr.push(i);
            }
        }
        return ans;
    }

    int maximalRectangle(vector<vector<char>> &matrix)
    {
        vector<int> inp = vector<int>(matrix[0].size(), 0);
        int ans = 0;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                if (matrix[i][j] == '0')
                {
                    inp[j] = 0;
                }
                else
                {
                    inp[j]++;
                }
            }
            ans = max(ans, largestRectangleArea(inp));
        }
        return ans;
    }
};

int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}