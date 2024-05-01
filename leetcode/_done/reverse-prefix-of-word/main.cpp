#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
#include <queue>
using namespace std;

// daily-question 2024-05-01
class Solution
{
public:
    string reversePrefix(string word, char ch)
    {
        int idx = -1;
        stack<char> builder;
        for (int i = 0; i < word.length(); i++)
        {
            builder.push(word[i]);
            if (word[i] == ch)
            {
                idx = i;
                break;
            }
        }
        if (idx == -1)
        {
            return word;
        }

        string ans = "";
        while (!builder.empty())
        {
            ans += builder.top();
            builder.pop();
        }
        word.erase(word.begin(), word.begin() + idx + 1);
        ans += word;
        return ans;
    }
};

int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}