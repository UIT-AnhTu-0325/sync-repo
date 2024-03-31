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
    long long countSubarrays(vector<int> &nums, int minK, int maxK)
    {
        int left = 0, right = 0;
        int posMin = -1, posMax = -1;
        int ans = 0;

        while (right < 0)
        {
            if (maxK < nums[right] || minK > nums[right])
            {
                if (posMin != posMax && posMin != -1 && posMax != -1)
                {
                    int cLeft = min(posMin, posMax) - left + 1;
                    int cRight = right - max(posMin, posMax) + 1;
                    ans += ((cLeft + 1) * (cRight + 1));
                    posMin = -1;
                    posMax = -1;
                }

                left = right;
            }

            if (nums[right] == minK)
            {
                posMin = right;
            }

            if (nums[right] == maxK)
            {
                posMax = right;
            }

            right++;
        }

        return ans;
    }
};
int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}