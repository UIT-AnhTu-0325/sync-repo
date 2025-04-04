#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
using namespace std;

class Solution
{
public:
    bool compare(vector<int> v1, vector<int> v2)
    {
        return v2[0] - v1[0] > 0;
    }

    int findMinArrowShots(vector<vector<int>> &points)
    {
        int n = points.size();
        sort(points.begin(), points.end(), compare);

        int res = 1;
        vector<int> crr = points[0];
        for (int i = 0; i < n; i++)
        {
            if (crr[1] >= points[i][0])
            {
                crr[1] = min(points[i][1], crr[1]);
            }
            else
            {
                res += 1;
                crr = points[i];
            }
        }
        return res;
    }
};
int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}