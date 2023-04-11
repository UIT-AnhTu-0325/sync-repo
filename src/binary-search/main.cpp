#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int binSearch(vector<int> &nums, int left, int right, int target)
{
    int mid = (left + right) / 2;
    if (nums[mid] == target)
        return mid;
    if (right <= left)
    {
        return -1;
    }

    if (nums[mid] > target)
    {
        return binSearch(nums, left, mid, target);
    }
    else
    {
        return binSearch(nums, mid + 1, right, target);
    }
}

int search(vector<int> &nums, int target)
{
    return binSearch(nums, 0, nums.size() - 1, target);
}

int main()
{
    vector<int> myVector{-1, 0, 3, 5, 9, 12};
    cout << search(myVector, 2);
}