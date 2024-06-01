#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
#include <queue>
using namespace std;

// daily-question 2024-06-01
class Solution
{
public:
    int scoreOfString(string s)
    {
        int score = 0;
        for (int i = 0; i < s.size() - 1; ++i)
        {
            score += abs(s[i] - s[i + 1]);
        }
        return score;
    }
};

int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}