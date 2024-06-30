#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
#include <queue>
using namespace std;

// daily-question 2024-06-05
class Solution
{
public:
    vector<string> commonChars(vector<string> &words)
    {
        unordered_map<char, int> calc;

        for (int i = 0; i < words.size(); i++)
        {
            unordered_map<char, int> umap;
            for (char c : words[i])
            {
                if (umap.find(c) == umap.end())
                    umap[c] = 1;
                else
                    umap[c]++;
            }

            if (i == 0)
                calc = umap;
            else
            {
                for (pair<char, int> p : calc)
                {
                    calc[p.first] = min(p.second, umap[p.first]);
                }
            }
        }
        vector<string> ans;

        for (pair<char, int> p : calc)
        {
            for (int i = 0; i < p.second; i++)
            {
                string s = "";
                s += p.first;
                ans.push_back(s);
            }
        }

        return ans;
    }
};

int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}