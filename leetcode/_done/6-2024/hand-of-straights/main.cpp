#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
#include <queue>
using namespace std;

// daily-question 2024-06-06
class Solution
{
public:
    bool isNStraightHand(vector<int> &hand, int groupSize)
    {
        vector<pair<int, int>> build;
        sort(hand.begin(), hand.end());
        for (int num : hand)
        {
            if (build.empty() || build.back().first != num)
                build.push_back({num, 1});
            else
                build.back().second++;
        }
        while (true)
        {
            while (!build.empty() && build.front().second == 0)
                build.erase(build.begin());
            if (build.empty())
                return true;
            if (build.size() < groupSize)
                return false;
            build.front().second--;
            for (int i = 1; i < groupSize; i++)
            {
                if (build[i].first != build[i - 1].first + 1)
                    return false;
                build[i].second--;
                if (build[i].second < 0)
                    return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution *solution = new Solution();
    vector<int> inp = {3, 4, 7, 4, 6, 3, 6, 5, 2, 8};
    solution->isNStraightHand(inp, 2);
    cout << "Hello world";
}