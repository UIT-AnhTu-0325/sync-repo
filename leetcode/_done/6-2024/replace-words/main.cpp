#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
#include <queue>
using namespace std;

// daily-question 2024-06-07
class Solution
{
public:
    vector<string> splitStringBySpace(const string &sentence)
    {
        vector<string> result;
        stringstream ss(sentence);
        string word;

        while (ss >> word)
        {
            result.push_back(word);
        }

        return result;
    }

    bool startsWith(const string &a, const string &b)
    {
        if (b.size() > a.size())
        {
            return false;
        }
        return a.compare(0, b.size(), b) == 0;
    }

    string replaceWords(vector<string> &dictionary, string sentence)
    {
        sort(dictionary.begin(), dictionary.end(), [](const string &a, const string &b)
             { return a.size() < b.size(); });

        vector<string> words = splitStringBySpace(sentence);
        for (int i = 0; i < words.size(); i++)
        {
            for (string item : dictionary)
            {
                if (startsWith(words[i], item))
                {
                    words[i] = item;
                    break;
                }
            }
        }
        string res = words[0];
        for (int i = 1; i < words.size(); i++)
        {
            res += " ";
            res += words[i];
        }
        return res;
    }
};

int main()
{
    Solution *solution = new Solution();
    vector<string> inp = {"cat", "bat", "rat"};
    string sentence = "the cattle was rattled by the battery";
    solution->replaceWords(inp, sentence);
    cout << "Hello world";
}