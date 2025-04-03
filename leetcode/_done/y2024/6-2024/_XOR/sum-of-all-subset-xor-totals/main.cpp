#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
#include <queue>
using namespace std;

// So fuckin hard but also so fuckin fun
class Solution
{
public:
    int subsetXORSum(vector<int> &nums)
    {
        int result = 0;
        // Capture each bit that is set in any of the elements
        for (int num : nums)
        {
            result |= num;
        }
        // Multiply by the number of subset XOR totals that will have each bit set
        return result << (nums.size() - 1);
    }
};

int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}