#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
#include <queue>
using namespace std;

// daily-question 2024-05-27
class Solution
{
public:
    int specialArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> frequency(n + 1, 0);

        for (int num : nums)
        {
            frequency[min(n, num)]++;
        }

        int countGreate = 0;
        for (int i = n; i > 0; i--)
        {
            countGreate += frequency[i];
            if (countGreate == i)
                return i;
        }
        return -1;
    }
};

int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}