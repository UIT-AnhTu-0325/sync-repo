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
    string customSortString(string order, string s)
    {
        string result = "";
        unordered_map<int,int>mp;
        for(char it : s){
            mp[it]++;
        }
        for(char it : order){
            if(mp.find(it) != mp.end())
                result.append(mp[it], it);
                mp.erase(it);
        }
        for(pair<int, int> it : mp){
            result.append(it.second,it.first);
        }
        return result;
    }
};
int main()
{
    Solution *solution = new Solution();
    string res = solution->customSortString("exv", "xwvee");
    cout << res;
}