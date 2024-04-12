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
    vector<int> deckRevealedIncreasing(vector<int> &deck)
    {
        sort(deck.begin(), deck.end());
        vector<int> res;

        while (deck.size() > 0)
        {

            int last = deck[deck.size() - 1];
            if (res.size() == 0)
            {
                res.push_back(last);
            }
            else
            {
                int lastRes = res[res.size() - 1];
                res.pop_back();
                res.insert(res.begin(), lastRes);
                res.insert(res.begin(), last);
            }
            deck.pop_back();
        }
        return res;
    }
};
int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}