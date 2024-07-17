#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
#include <queue>
using namespace std;

// daily-question 2024-05-24
class Solution
{
public:
    int maxScore = 0;

    void back_track(int start, int crrScore, vector<string> &words, vector<int> pools, vector<int> &score)
    {

        maxScore = max(crrScore, maxScore);

        for (int i = start; i < words.size(); i++)
        {
            string word = words[i];
            int wordScore = 0;
            bool canFit = true;

            vector<int> tmpPools = pools;

            for (int j = 0; j < word.length(); j++)
            {
                wordScore += score[word[j] - 'a'];
                tmpPools[word[j] - 'a']--;
                if (tmpPools[word[j] - 'a'] < 0)
                {
                    canFit = false;
                    break;
                }
            }

            if (!canFit)
                continue;

            back_track(i + 1, crrScore + wordScore, words, tmpPools, score);
        }
    }

    int maxScoreWords(vector<string> &words, vector<char> &letters, vector<int> &score)
    {
        vector<int> pools = vector<int>(26, 0);
        for (int i = 0; i < letters.size(); i++)
        {
            pools[letters[i] - 'a']++;
        }

        back_track(0, 0, words, pools, score);

        return maxScore;
    }
};

int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}