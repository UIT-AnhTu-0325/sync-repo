#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
#include <queue>
#include <bitset>
using namespace std;

// daily-question 2024-07-01
class Solution
{
public:
    bool threeConsecutiveOdds(vector<int> &arr)
    {
        if (arr.size() <= 2)
            return false;
        for (int i = 1; i < arr.size() - 1; i++)
        {
            if (arr[i - 1] % 2 == 1 && arr[i] % 2 == 1 && arr[i + 1] % 2 == 1)
                return true;
        }
        return false;
    }
};

int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}