#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
#include <queue>
using namespace std;

// daily-question 2024-05-09
class Solution
{
public:
    long long maximumHappinessSum(vector<int> &happiness, int k)
    {
        sort(happiness.begin(), happiness.end(), greater<int>());
        long long ans = 0;

        for (int i = 0; i < k; i++)
        {
            ans += max(happiness[i] - i, 0);
        }
        return ans;
    }
};
int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}