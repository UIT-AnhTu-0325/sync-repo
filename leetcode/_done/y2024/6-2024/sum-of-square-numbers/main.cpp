#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
#include <queue>
using namespace std;

// daily-question 2024-06-17
#define ll long long
class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        ll left = 0, right = static_cast<ll>(sqrt(c));
        while (left <= right)
        {
            if (left * left + right * right == c)
                return true;
            else if (left * left + right * right > c)
                right--;
            else
                left++;
        }

        return false;
    }
};

int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}