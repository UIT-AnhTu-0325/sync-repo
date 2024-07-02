#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
#include <queue>
using namespace std;

// daily-question 2024-06-20
class Solution
{
public:
    bool canFit(vector<int> &position, int m, int length)
    {
        int pos = position[0];
        int count = 1;
        for (int i = 0; i < position.size(); i++)
        {
            if (position[i] - pos >= length)
            {
                count++;
                pos = position[i];
            }

            if (count >= m)
                return true;
        }
        return false;
    }
    int calc(vector<int> &position, int m, int start, int end)
    {
        if (start > end)
            return -1;
        int lenMid = (end + start) / 2;
        if (canFit(position, m, lenMid))
        {
            int resNext = calc(position, m, lenMid + 1, end);
            if (resNext != -1)
            {
                return resNext;
            }
            else
            {
                return lenMid;
            }
        }
        else
            return calc(position, m, start, lenMid - 1);
    }

    int maxDistance(vector<int> &position, int m)
    {
        sort(position.begin(), position.end());
        int start = 1, end = *max_element(position.begin(), position.end());
        return calc(position, m, start, end);
    }
};

int main()
{
    vector<int> inp = {5, 4, 3, 2, 1, 1000000000};
    int m = 2;
    Solution *solution = new Solution();
    solution->maxDistance(inp, m);
    cout << "Hello world";
}