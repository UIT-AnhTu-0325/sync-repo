#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
#include <queue>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();

        vector<int> leftTallest = {0};
        int tallest = 0;
        for (int i = 1; i < n; i++)
        {
            tallest = max(tallest, height[i - 1]);
            leftTallest.push_back(tallest);
        }

        vector<int> rightTallest = {0};
        tallest = 0;
        for (int i = n - 2; i >= 0; i--)
        {
            tallest = max(tallest, height[i + 1]);
            rightTallest.insert(rightTallest.begin(), tallest);
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (height[i] > leftTallest[i] || height[i] > rightTallest[i])
                continue;
            else
            {
                ans += min(leftTallest[i], rightTallest[i]) - height[i];
            }
        }
        return ans;
    }
};

class Solution2 {
public:
    int trap(std::vector<int>& height) {
        int i = 0, left_max = height[0], sum = 0;
        int j = height.size() - 1, right_max = height[j];
        while (i < j) {
            if (left_max <= right_max) {
                sum += (left_max - height[i]);
                i++;
                left_max = std::max(left_max, height[i]);
            } else {
                sum += (right_max - height[j]);
                j--;
                right_max = std::max(right_max, height[j]);
            }
        }
        return sum;
    }
};

int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}