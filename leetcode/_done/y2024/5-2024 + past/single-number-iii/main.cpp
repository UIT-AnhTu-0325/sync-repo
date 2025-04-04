#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
#include <queue>
using namespace std;

// daily-question 2024-05-31
class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        int xor2diff = 0;
        for (int num : nums)
        {
            xor2diff ^= num;
        }
        int i = 0;
        while (((xor2diff >> i) & 1) == 0)
        {
            i++;
        }

        int x1 = 0, x2 = 0;
        for (int num : nums)
        {
            if (((num >> i) & 1) == 0)
            {
                x1 ^= num;
            }
            else
            {
                x2 ^= num;
            }
        }

        return vector<int>{x1, x2};
    }
};

int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}