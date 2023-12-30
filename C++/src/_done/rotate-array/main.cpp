#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

void rotate(vector<int> &nums, int k)
{
    int nSize = nums.size();
    int times = k % nSize;
    vector<int> copy = vector<int>();
    for (int i = 0; i < nSize; i++)
    {
        copy.push_back(nums[i]);
    }
    // int tmp = nums[0];
    for (int i = 0; i < nSize; i++)
    {
        nums[i] = copy[(nSize - times + i) % nSize];
    }
    // nums[(nSize - times) % nSize] = tmp;
}

int main()
{
    // vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    vector<int> nums = {-1,-100,3,99};
    int k = 2;
    rotate(nums, k);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << "   ";
    }
}