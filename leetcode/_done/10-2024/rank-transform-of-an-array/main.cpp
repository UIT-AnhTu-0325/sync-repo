#include <algorithm>
#include <bitset>
#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        // Store the rank for each number in arr
        map<int, int> numToRank;
        vector<int> sortedArr(arr);
        sort(sortedArr.begin(), sortedArr.end());
        int rank = 1;
        for (int i = 0; i < sortedArr.size(); i++) {
            if (i > 0 && sortedArr[i] > sortedArr[i - 1]) {
                rank++;
            }
            numToRank[sortedArr[i]] = rank;
        }
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = numToRank[arr[i]];
        }
        return arr;
    }
};
int main() {
    Solution* solution = new Solution();
    cout << "Hello world";
}