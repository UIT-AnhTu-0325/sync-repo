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
    int findMaxLength(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> mp;
        int sum = 0;
        int subArray_length = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i] == 0 ? -1 : 1;
            if (sum == 0)
            {
                subArray_length = i + 1;
            }
            else if (mp.find(sum) != mp.end())
            {
                subArray_length = max(subArray_length, i - mp[sum]);
            }
            else
            {
                mp[sum] = i;
            }
        }
        return subArray_length;
    };
};

int main()
{
    Solution *solution = new Solution();
    static const int arr[] = {0, 1, 0, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1};
    vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
    int t = solution->findMaxLength(vec);
    cout << "Hello world"
         << "  " << t;
}