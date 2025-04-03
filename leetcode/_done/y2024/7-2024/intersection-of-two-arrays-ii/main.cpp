#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
#include <queue>
#include <bitset>
using namespace std;

// daily-question 2024-07-02
class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> res;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int minLen = min(nums1.size(), nums2.size());
        int idx1 = 0, idx2 = 0;
        while ((idx1 < minLen || idx2 < minLen) && idx1 < nums1.size() && idx2 < nums2.size())
        {
            if (nums1[idx1] == nums2[idx2])
            {
                res.push_back(nums1[idx1]);
                idx1++;
                idx2++;
            }
            else if (nums1[idx1] > nums2[idx2])
            {
                idx2++;
            }
            else
            {
                idx1++;
            }
        }
        return res;
    }
};

int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}