#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
#include <queue>
using namespace std;

// daily-question 2024-06-18
class Solution
{
public:
    int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker)
    {
        int n = difficulty.size();
        vector<pair<int, int>> diffPro;
        for (int i = 0; i < n; i++)
        {
            diffPro.push_back({difficulty[i], profit[i]});
        }
        sort(diffPro.begin(), diffPro.end());
        vector<pair<int, int>> maxProf = {diffPro.front()};
        for (int i = 1; i < n; i++)
        {
            if (diffPro[i].second > maxProf.back().second)
            {
                maxProf.push_back(diffPro[i]);
            }
            else
            {
                maxProf.push_back({diffPro[i].first, maxProf.back().second});
            }
        }

        int res = 0;

        for (int i = 0; i < worker.size(); i++)
        {
            int j = 0;
            while (j < n && maxProf[j].first <= worker[i])
            {
                j++;
                if(j == n) break;
            }
            if (j == 0)
                continue;
            res += maxProf[j - 1].second;
        }
        return res;
    }
};

int main()
{
    vector<int> difficulty = {13, 37, 58};
    vector<int> profit = {4, 90, 96};
    vector<int> worker = {34, 73, 45};
    Solution *solution = new Solution();
    solution->maxProfitAssignment(difficulty, profit, worker);
    cout << "Hello world";
}