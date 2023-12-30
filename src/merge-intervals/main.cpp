#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> result = vector<vector<int>>();
    vector<int> item = vector<int>();

    for (int i = 0; i < intervals.size(); i++)
    {
        if (item.size() == 0)
        {
            item.push_back(intervals[i][0]);
            item.push_back(intervals[i][1]);
        }
        else
        {
            if (item[1] >= intervals[i][0])
            {
                item[1] = intervals[i][1] > item[1] ? intervals[i][1] : item[1];
            }
            else
            {
                result.push_back(item);
                item = vector<int>();
                item.push_back(intervals[i][0]);
                item.push_back(intervals[i][1]);
            }
        }
    }
    result.push_back(item);
    return result;
}

int main()
{
}