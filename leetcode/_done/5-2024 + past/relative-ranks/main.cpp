#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
#include <queue>
using namespace std;

// daily-question 2024-05-08
class Solution
{
public:
    vector<string> findRelativeRanks(vector<int> &score)
    {
        string first = "Gold Medal";
        string second = "Silver Medal";
        string third = "Bronze Medal";

        vector<int> src = vector(score);
        sort(score.begin(), score.end());
        unordered_map<int, int> build;
        for (int i = 0; i < score.size(); i++)
        {
            build[score[i]] = score.size() - i - 1;
        }
        vector<string> ans;
        for (int i = 0; i < src.size(); i++)
        {
            if (build[src[i]] == 0)
            {
                ans.push_back(first);
            }
            else if (build[src[i]] == 1)
            {
                ans.push_back(second);
            }
            else if (build[src[i]] == 2)
            {
                ans.push_back(third);
            }
            else
            {
                ans.push_back(to_string(build[src[i]] + 1));
            }
        }
        return ans;
    }
};

int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}