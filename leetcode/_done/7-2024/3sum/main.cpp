#include <algorithm>
#include <bitset>
#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// I think i can optimize it
class Solution {
  public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        int n = nums.size();
        int left = 0;
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        unordered_map<int, pair<int, int>> calc;

        for (int i = 0; i < n; i++) {
            if (calc.find(nums[i]) == calc.end()) {
                calc[nums[i]] = {i, i};
            } else {
                calc[nums[i]].second = i;
            }
        }

        while (left < n && nums[left] <= 0) {
            int right = n - 1;
            int crrLeft = nums[left];

            while (right > left && nums[right] >= 0) {
                int crrRight = nums[right];

                int sum = (nums[left] + nums[right]) * -1;
                if (calc.find(sum) != calc.end()) {
                    double middle = (calc[sum].first + calc[sum].second) / (double)2;
                    if (middle > left && middle < right) {
                        if (calc[sum].first == left && calc[sum].second == right && left - right == -1) {

                        } else {

                            res.push_back({nums[left], nums[right], sum});
                        }
                    }
                }

                while (right >= 0 && nums[right] == crrRight) {
                    right--;
                }
            }

            while (left < n && nums[left] == crrLeft) {
                left++;
            }
        }

        return res;
    }
};

// TLE-2 Solution :)
class Solution2 {
  public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        int n = nums.size();
        int left = 0;
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        while (left < n && nums[left] <= 0) {
            int right = n - 1;
            int crrLeft = nums[left];

            while (right > left && nums[right] >= 0) {
                int crrRight = nums[right];
                for (int i = left + 1; i <= right - 1; i++) {
                    if (nums[left] + nums[right] == -1 * nums[i]) {
                        res.push_back({nums[left], nums[right], nums[i]});
                        break;
                    }
                }
                while (right >= 0 && nums[right] == crrRight) {
                    right--;
                }
            }

            while (left < n && nums[left] == crrLeft) {
                left++;
            }
        }

        return res;
    }
};

// TLE Solution
class Solution1 {
  public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        int n = nums.size();
        unordered_map<int, vector<pair<int, int>>> calc;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int sum = nums[i] + nums[j];
                if (calc.find(sum) == calc.end()) {
                    calc[sum] = {{i, j}};
                } else {
                    calc[sum].push_back({i, j});
                }
            }
        }
        vector<vector<int>> res;
        unordered_map<int, unordered_map<int, bool>> visited;
        for (int i = 0; i < n; i++) {
            if (calc.find(nums[i] * -1) == calc.end())
                continue;
            vector<pair<int, int>> matches = calc[nums[i] * -1];
            for (pair<int, int> match : matches) {
                if (match.first == i || match.second == i)
                    continue;
                int numFirst = nums[match.first];
                int numSec = nums[match.second];
                int numThird = nums[i];

                if (visited.find(numFirst) == visited.end() ||
                    (visited[numFirst].find(numSec) == visited[numFirst].end() &&
                     visited[numFirst].find(numThird) == visited[numFirst].end())) {
                    res.push_back({numFirst, numSec, numThird});
                    visited[numFirst][numSec] = true;
                    visited[numSec][numFirst] = true;
                    visited[numThird][numFirst] = true;
                }
            }
        }

        return res;
    }
};

int main() {
    vector<int> inp = {0, 0, 0};
    Solution *solution = new Solution();
    solution->threeSum(inp);
    cout << "Hello world";
}