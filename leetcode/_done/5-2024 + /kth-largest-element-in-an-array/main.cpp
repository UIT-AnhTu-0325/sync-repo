#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int findKthLargest(vector<int> &nums, int k)
{
    return 100;
}

int main()
{
    vector<int> nums;
    int n, k;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        nums.push_back(input);
    }
    cin >> k;
    cout << findKthLargest(nums, k);
}