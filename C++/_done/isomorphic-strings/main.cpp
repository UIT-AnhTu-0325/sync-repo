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
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, char> umap1;
        unordered_map<char, char> umap2;
        for (int i = 0; i < s.length(); i++)
        {
            if (umap1.find(s[i]) == umap1.end() && umap2.find(t[i]) == umap2.end())
            {
                umap1[s[i]] = t[i];
                umap2[t[i]] = s[i];
            }
            else
            {
                if (umap1[s[i]] != t[i] || umap2[t[i]] != s[i])
                {
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}