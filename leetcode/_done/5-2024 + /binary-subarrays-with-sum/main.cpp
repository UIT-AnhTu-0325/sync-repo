#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
using namespace std;

class Solution
{
public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        unordered_map<int, int> count;
        count[0] = 1;
        int curr_sum = 0;
        int total_subarrays = 0;

        for (int num : nums)
        {
            curr_sum += num;
            if (count.find(curr_sum - goal) != count.end())
            {
                total_subarrays += count[curr_sum - goal];
            }
            count[curr_sum]++;
        }

        return total_subarrays;
    }
};

int main()
{
    Solution *solution = new Solution();

    vector<int> test = {1, 0, 1, 0, 1};
    solution->numSubarraysWithSum(test, 2);

    cout << "Hello world";
}