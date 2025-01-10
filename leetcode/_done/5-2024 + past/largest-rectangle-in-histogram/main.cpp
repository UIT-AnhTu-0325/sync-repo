#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
#include <queue>
using namespace std;

// https://www.youtube.com/watch?v=jC_cWLy7jSI

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
};

int main()
{
    vector<int> inp = {1};
    Solution *solution = new Solution();
    solution->largestRectangleArea(inp);
    cout << "Hello world";
}