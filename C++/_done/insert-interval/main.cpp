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
    bool canMerge(vector<int> v1, vector<int> v2)
    {
        if (v1[1] < v2[0] || v1[0] > v2[1])
        {
            return false;
        }
        return true;
    }

    vector<int> merge(vector<int> v1, vector<int> v2)
    {
        vector<int> res;
        res.push_back(min(v1[0], v2[0]));
        res.push_back(max(v1[1], v2[1]));
        return res;
    }

    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> res;
        bool isPushed = false;
        for (int i = 0; i < intervals.size(); i++)
        {
            bool can = canMerge(intervals[i], newInterval);
            if (!can)
            {
                if (intervals[i][0] > newInterval[1] && !isPushed)
                {
                    res.push_back(newInterval);
                    isPushed = true;
                }
                res.push_back(intervals[i]);
            }
            else
            {
                newInterval = merge(intervals[i], newInterval);
            }
        }

        if (!isPushed)
            res.push_back(newInterval);

        return res;
    }
};

int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}