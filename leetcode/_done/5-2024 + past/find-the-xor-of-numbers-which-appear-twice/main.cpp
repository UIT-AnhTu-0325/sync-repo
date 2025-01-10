#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
#include <queue>
using namespace std;

class Solution
{
public:
    int duplicateNumbersXOR(vector<int> &nums)
    {
        int ans = 0;
        unordered_map<int, int> freq;
        for (auto n : nums)
        {
            freq[n]++;
        }
        for (auto [k, v] : freq)
        {
            if (v == 2)
                ans = ans ^ k;
        }
        return ans;
    }
};

int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}