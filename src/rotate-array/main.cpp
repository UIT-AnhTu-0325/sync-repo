#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

void rotate(vector<int> &nums, int k)
{
    int times = k % nums.size();
    while (times > 0)
    {
        int tmp = nums[nums.size() - 1];
        for (int i = nums.size() - 1; i > 0; i--)
        {
            nums[i] = nums[i - 1];
        }
        nums[0] = tmp;
        times--;
    }
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 8;
    rotate(nums, k);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << "   ";
    }
}