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
    vector<int> findDuplicates(vector<int> &nums)
    {
        nums = vector<int>{1, 1, 2};

        int size = nums.size();

        for (int i = 0; i < size; i++)
        {
            int idx = 0;
            if (nums[i] > size)
            {
                idx = abs(nums[i]) - size;
            }
            else
            {

                idx = abs(nums[i]);
            }
            idx -= 1;
            if (nums[idx] > 0)
            {
                nums[idx] *= -1;
            }
            else
            {
                nums[idx] = abs(nums[idx]) + size;
            }
        }

        vector<int> res;
        for (int i = 0; i < size; i++)
        {
            if (nums[i] > size)
            {
                res.push_back(i + 1);
            }
        }
        return res;
    }
};

int main()
{
    Solution *solution = new Solution();
    vector<int> arr;
    solution->findDuplicates(arr);
    cout << "Hello world";
}