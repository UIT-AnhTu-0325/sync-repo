#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
#include <queue>
using namespace std;

// daily-question 2024-05-23
class Solution
{
private:
    int countBeautifulSubsets(vector<pair<int, int>> &subsets, int numSubsets, int difference, int i, vector<int> &counts)
    {
        // Base case: if we've reached the end
        if (i == numSubsets)
        {
            return 1;
        }

        // If the count is already calculated, return it
        if (counts[i] != -1)
        {
            return counts[i];
        }

        // Calculate subsets where the current subset is not taken
        int skip = countBeautifulSubsets(subsets, numSubsets, difference, i + 1, counts);

        // Calculate subsets where the current subset is taken
        int take = (1 << subsets[i].second) - 1; // take the current subset

        // If the next number has a difference of 'difference', calculate subsets accordingly
        if (i + 1 < numSubsets && subsets[i + 1].first - subsets[i].first == difference)
        {
            take *= countBeautifulSubsets(subsets, numSubsets, difference, i + 2, counts);
        }
        else
        {
            take *= countBeautifulSubsets(subsets, numSubsets, difference, i + 1, counts);
        }

        return counts[i] = skip + take; // Store and return total count of subsets
    }

public:
    int beautifulSubsets(vector<int> &nums, int difference)
    {
        int totCount = 1;
        unordered_map<int, unordered_map<int, int>> freqMap;

        // Calculate frequencies based on remainder
        for (int &num : nums)
        {
            freqMap[num % difference][num]++;
        }

        // Calculate subsets for each remainder group
        for (auto &fr : freqMap)
        {
            vector<pair<int, int>> subsets(fr.second.begin(), fr.second.end());
            vector<int> counts(subsets.size(), -1); // Store counts of subsets for memoization
            totCount *= countBeautifulSubsets(subsets, subsets.size(), difference, 0, counts);
        }
        return totCount - 1;
    }
};

int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}