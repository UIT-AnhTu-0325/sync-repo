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
    unordered_map<string, int> _dic;
    int n;
    string str;
    vector<string> res;

    void back_track(int start, vector<string> build)
    {
        if (start == n)
        {
            string buildRes;
            for (int i = 0; i < build.size(); i++)
            {
                if (i != 0)
                    buildRes += " ";
                buildRes += build[i];
            }
            res.push_back(buildRes);
        }
        for (int i = start; i < n; i++)
        {
            string newWord = str.substr(start, i - start + 1);
            if (_dic.find(newWord) == _dic.end())
                continue;
            build.push_back(newWord);
            back_track(i + 1, build);
            build.pop_back();
        }
    }

    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        n = s.size();
        str = s;
        for (int i = 0; i < wordDict.size(); i++)
        {
            _dic[wordDict[i]] = 1;
        }

        back_track(0, vector<string>{});
        return res;
    }
};

int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}