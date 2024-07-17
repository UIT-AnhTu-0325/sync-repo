#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int removeElement(vector<int> &nums, int val)
{
    vector<int> res = vector<int>();
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != val)
        {
            res.push_back(nums[i]);
        }
    }
    for (int i = 0; i < res.size(); i++)
    {
        nums[i] = res[i];
    }
    return res.size();
}

int main()
{
}