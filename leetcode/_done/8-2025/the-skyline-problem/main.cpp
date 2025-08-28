#include <algorithm>
#include <bitset>
#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#include <set>
using namespace std;

class Solution
{
public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
    {
        vector<vector<int>> ans;
        multiset<int> pq{0};

        vector<pair<int, int>> points;

        for (auto b : buildings)
        {
            points.push_back(pair<int, int>(b[0], -b[2]));
            points.push_back(pair<int, int>(b[1], b[2]));
        }

        sort(points.begin(), points.end());

        int crrHeight = 0;
        for (auto p : points)
        {
            if (p.second < 0)
            {
                pq.insert(-p.second);
            }
            else
            {
                pq.erase(pq.find(p.second));
            }

            if (crrHeight != *pq.rbegin())
            {
                ans.push_back(vector<int>{p.first, *pq.rbegin()});
                crrHeight = *pq.rbegin();
            }
        }

        return ans;
    }
};

int main()
{
    vector<vector<int>> buildings = {
        {2, 9, 10},
        {3, 7, 15},
        {5, 12, 12},
        {15, 20, 10},
        {19, 24, 8}};
    Solution *solution = new Solution();
    solution->getSkyline(buildings);
    cout << "Hello world";
}