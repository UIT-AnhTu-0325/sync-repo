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
    int openLock(vector<string> &deadends, string target)
    {
        queue<pair<string, int>> build;
        build.push(make_pair(string("0000"), 0));
        unordered_map<string, int> traveled;

        while (!build.empty())
        {
            string crr = build.front().first;
            int num = build.front().second;

            if (!(traveled.find(crr) == traveled.end()))
            {
                build.pop();
                continue;
            }
            traveled[crr] = true;

            if (crr == target)
            {
                return num;
            }

            bool isEnd = false;
            for (int i = 0; i < deadends.size(); i++)
            {
                if (deadends[i] == crr)
                {
                    isEnd = true;
                    break;
                }
            }
            if (isEnd)
                continue;

            for (int i = 0; i < 4; i++)
            {
                char crrIdx = crr[i];

                crr[i] = (crrIdx == '0') ? '9' : crrIdx - 1;
                build.push(make_pair(string(crr), num + 1));

                crr[i] = (crrIdx == '9') ? '0' : crrIdx + 1;
                build.push(make_pair(string(crr), num + 1));

                crr[i] = crrIdx;
            }

            build.pop();
        }

        return -1;
    }
};

int main()
{
    Solution *solution = new Solution();
    vector<string> inp = {"0201", "0101", "0102", "1212", "2002"};
    solution->openLock(inp, "0202");
    cout << "Hello world";
}