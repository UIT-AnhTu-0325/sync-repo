#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
#include <queue>
using namespace std;

// daily-question 2024-06-24
// it really hard for me
class Solution
{
public:
    int minKBitFlips(vector<int> &nums, int k)
    {
        // Keeps track of flipped states
        vector<bool> flipped(nums.size(), false);
        // Tracks valid flips within the past window
        int validFlipsFromPastWindow = 0;
        // Counts total flips needed
        int flipCount = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (i >= k)
            {
                // Decrease count of valid flips from the past window if needed
                if (flipped[i - k])
                {
                    validFlipsFromPastWindow--;
                }
            }

            // Check if current bit needs to be flipped
            if (validFlipsFromPastWindow % 2 == nums[i])
            {
                // If flipping the window extends beyond the array length,
                // return -1
                if (i + k > nums.size())
                {
                    return -1;
                }
                // Increment the count of valid flips and mark current as
                // flipped
                validFlipsFromPastWindow++;
                flipped[i] = true;
                flipCount++;
            }
        }

        return flipCount;
    }
};

int main()
{
    vector<int> inp = {0, 0, 0, 1, 0, 1, 1, 0};
    Solution *solution = new Solution();
    solution->minKBitFlips(inp, 3);
    cout << "Hello world";
}