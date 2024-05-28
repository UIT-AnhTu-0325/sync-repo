#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

vector<int> sortedSquares(vector<int> &nums)
{
    vector<int> res;
    int pos = 0;
    while (pos < nums.size() && nums[pos] < 0)
    {
        pos++;
    }
    int posL = pos - 1;
    while (posL > -1 && pos < nums.size())
    {
        if (-1 * nums[posL] < nums[pos])
        {
            res.push_back(nums[posL] * nums[posL]);
            posL--;
        }
        else
        {
            res.push_back(nums[pos] * nums[pos]);
            pos++;
        }
    }
    while (posL > -1)
    {
        res.push_back(nums[posL] * nums[posL]);
        posL--;
    }
    while (pos < nums.size())
    {
        res.push_back(nums[pos] * nums[pos]);
        pos++;
    }
    return res;
}

int main()
{
    vector<int> nums = vector<int>{-1};
    vector<int> res = sortedSquares(nums);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << "  ";
    }
}