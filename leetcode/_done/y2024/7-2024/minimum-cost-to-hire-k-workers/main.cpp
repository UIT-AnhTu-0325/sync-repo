#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
#include <queue>
using namespace std;

// daily-question 2024-05-12
// I just miss the priority queue. hope enjoy it in the future
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage,
                                int k) {
        int n = quality.size();
        double totalCost = numeric_limits<double>::max();
        double currentTotalQuality = 0;
        // Store wage-to-quality ratio along with quality
        vector<pair<double, int>> wageToQualityRatio;

        // Calculate wage-to-quality ratio for each worker
        for (int i = 0; i < n; i++) {
            wageToQualityRatio.push_back(
                {static_cast<double>(wage[i]) / quality[i], quality[i]});
        }

        // Sort workers based on their wage-to-quality ratio
        sort(wageToQualityRatio.begin(), wageToQualityRatio.end());

        // Use a priority queue to keep track of the highest quality workers
        priority_queue<int> workers;

        // Iterate through workers
        for (int i = 0; i < n; i++) {
            workers.push(wageToQualityRatio[i].second);
            currentTotalQuality += wageToQualityRatio[i].second;

            // If we have more than k workers,
            // remove the one with the highest quality
            if (workers.size() > k) {
                currentTotalQuality -= workers.top();
                workers.pop();
            }

            // If we have exactly k workers,
            // calculate the total cost and update if it's the minimum
            if (workers.size() == k) {
                totalCost = min(totalCost, currentTotalQuality *
                                               wageToQualityRatio[i].first);
            }
        }
        return totalCost;
    }
};

int main()
{
    vector<int> quality = {3, 1, 10, 10, 1};
    vector<int> wage = {4, 8, 2, 2, 7};
    int k = 3;

    Solution *solution = new Solution();
    solution->mincostToHireWorkers(quality, wage, k);
    cout << "Hello world";
}