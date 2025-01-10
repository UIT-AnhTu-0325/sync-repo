#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
#include <queue>
using namespace std;

// daily-question 2024-06-19
class Solution
{
public:
    int countOnDate(vector<int> &bloomDay, int k, int date)
    {
        int res = 0;
        int crrCount = 0;
        for (int i = 0; i < bloomDay.size(); i++)
        {
            if (bloomDay[i] <= date)
            {
                crrCount++;
            }
            else
            {
                crrCount = 0;
            }

            if (crrCount == k)
            {
                crrCount = 0;
                res++;
            }
        }
        return res;
    }
    int getDate(vector<int> &bloomDay, int m, int k, int start, int end)
    {
        if (start > end)
            return -1;
        int middle = (start + end) / 2;
        int cnt = countOnDate(bloomDay, k, middle);
        int cntBef = countOnDate(bloomDay, k, middle - 1);
        if (cnt == m || (cnt >= m && start == end))
        {
            if (cntBef < m)
                return middle;
            else
                return getDate(bloomDay, m, k, start, middle - 1);
        }
        if (cnt > m)
            return getDate(bloomDay, m, k, start, middle - 1);
        else
            return getDate(bloomDay, m, k, middle + 1, end);
    }

    int minDays(vector<int> &bloomDay, int m, int k)
    {
        int start = 0, end = *max_element(bloomDay.begin(), bloomDay.end());
        int date = getDate(bloomDay, m, k, start, end);
        if (date == -1)
            return -1;
        int crrMax = 0;
        // for (int i = 0; i < bloomDay.size(); i++)
        // {
        //     if (bloomDay[i] <= date)
        //         crrMax = max(bloomDay[i], crrMax);
        // }
        return date;
    }
};

int main()
{
    vector<int> inp = {1, 10, 3, 10, 2};
    int m = 3, k = 1;
    Solution *solution = new Solution();
    solution->minDays(inp, m, k);
    cout << "Hello world";
}