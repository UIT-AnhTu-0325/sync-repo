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
    bool checkArray(vector<int> &nums, int k)
    {
        nums.insert(nums.begin(), 0);
        nums.insert(nums.end(), 0);

        int sum = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            sum += (nums[i] - nums[i - 1]);
        }
        return sum == 0;
    }
};

int main()
{
    Solution *solution = new Solution();
    vector<int> inp = {60, 72, 87, 89, 63, 52, 64, 62, 31, 37, 57, 83, 98, 94, 92, 77, 94, 91, 87, 100, 91, 91, 50, 26};
    solution->checkArray(inp, 4);
    cout << "Hello world";
}