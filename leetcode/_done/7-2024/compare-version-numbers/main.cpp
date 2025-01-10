#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
#include <queue>
using namespace std;

// daily-question 2024-05-03
class Solution
{
public:
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

    int compareVersion(string version1, string version2)
    {
        vector<int> vv1 = splitStringByDot(version1);
        vector<int> vv2 = splitStringByDot(version2);

        int crrRes = 0;
        int i = 0, j = 0;
        while (i < vv1.size() && j < vv2.size())
        {
            if (vv1[i] < vv2[j])
                return -1;
            if (vv1[i] > vv2[j])
                return 1;
            i++;
            j++;
        }
        while (i < vv1.size())
        {
            if (vv1[i] > 0)
                return 1;
            i++;
        }
        while (j < vv2.size())
        {
            if (vv2[j] > 0)
                return -1;
            j++;
        }
        return 0;
    }
};

int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}