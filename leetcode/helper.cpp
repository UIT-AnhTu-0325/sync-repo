#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
#include <queue>
using namespace std;

/// @brief Init a hash for create a map with pair is key
struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2> &p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};
class Solution
{
    unordered_map<pair<string, int>, int, pair_hash> solved;
};

/// @brief these are ways to move in matrix
vector<vector<int>> adjs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

/// @brief count Frequency of vector
/// @param nums
void countFrequency(vector<int> &nums)
{
    int n = nums.size();
    vector<int> frequency(n + 1, 0);

    for (int num : nums)
    {
        frequency[min(n, num)]++;
    }
}

/// @brief sort vector of Pair
void sortPairVector(vector<int> &nums)
{
    vector<pair<int, int>> costs;
    sort(costs.begin(), costs.end(),
         [](const pair<int, int> &a, const pair<int, int> &b)
         { return a.second < b.second; });
}

/// @brief split string
/// @param str 
/// @return 
vector<int> splitStringByDot(const string &str)
    {
        vector<int> result;
        stringstream ss(str);
        string item;

        while (getline(ss, item, '.'))
        {
            result.push_back(stoi(item));
        }

        return result;
    }