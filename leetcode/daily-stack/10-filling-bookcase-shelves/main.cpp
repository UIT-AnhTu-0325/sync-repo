#include <algorithm>
#include <bitset>
#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// daily-question 2024-07-31
class Solution {
   public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int crrWidth = books[0][0], crrHeight = books[0][1];
        vector<int> d = vector<int>(books.size(), 0);
        d[0] = crrHeight;
    }
};

int main() {
    Solution* solution = new Solution();
    cout << "Hello world";
}