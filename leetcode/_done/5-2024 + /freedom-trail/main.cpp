#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
#include <queue>
using namespace std;

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
public:
    int RING_SIZE = 0;

    unordered_map<pair<string, int>, int, pair_hash> solved;

    int solve(string ring, string key, int startIdx)
    {
        if (key.length() == 0)
        {
            return 0;
        }

        char crrKey = key[0];
        key.erase(key.begin(), key.begin() + 1);

        if (ring[startIdx] == crrKey)
        {
            return 1 + solve(ring, key, startIdx);
        }

        int left = (startIdx - 1 + RING_SIZE) % RING_SIZE;
        int cLeft = 1;
        while (ring[left] != crrKey)
        {
            left = (left - 1 + RING_SIZE) % RING_SIZE;
            cLeft++;
        }

        int right = (startIdx + 1 + RING_SIZE) % RING_SIZE;
        int cRight = 1;
        while (ring[right] != crrKey)
        {
            right = (right + 1 + RING_SIZE) % RING_SIZE;
            cRight++;
        }

        int sLeft = INT32_MAX;
        if (solved.find(make_pair(key, left)) == solved.end())
        {

            sLeft = solve(ring, key, left) + cLeft + 1;
            solved[make_pair(key, left)] = sLeft - cLeft - 1;
        }
        else
        {
            sLeft = solved[make_pair(key, left)] + cLeft + 1;
        }

        int sRight = INT32_MAX;
        if (right == left)
        {
            sRight = sLeft - cLeft + cRight;
        }
        else
        {
            if (solved.find(make_pair(key, right)) == solved.end())
            {

                sRight = solve(ring, key, right) + cRight + 1;
                solved[make_pair(key, right)] = sRight - cRight - 1;
            }
            else
            {
                sRight = solved[make_pair(key, right)] + cRight + 1;
            }
        }

        return min(sLeft, sRight);
    }

    int findRotateSteps(string ring, string key)
    {
        RING_SIZE = ring.length();
        return solve(ring, key, 0);
    }
};

int main()
{
    Solution *solution = new Solution();
    string ring = "godding";
    string key = "gd";
    solution->findRotateSteps(ring, key);
    cout << "Hello world";
}