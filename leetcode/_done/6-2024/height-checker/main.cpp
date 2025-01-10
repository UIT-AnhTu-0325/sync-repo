#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
#include <queue>
using namespace std;

// daily-question 2024-06-10
class Solution
{
public:
    int heightChecker(vector<int> &heights)
    {
        vector<int> holder(heights);
        sort(heights.begin(), heights.end());
        int res = 0;
        for (int i = 0; i < heights.size(); i++)
        {
            if (heights[i] != holder[i])
                res++;
        }
        return res;
    }
};

int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}