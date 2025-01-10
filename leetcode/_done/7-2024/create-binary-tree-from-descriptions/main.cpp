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

// daily-question 2024-07-15
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
  public:
    TreeNode *createBinaryTree(vector<vector<int>> &descriptions) {
        unordered_map<int, TreeNode *> umap;
        unordered_map<int, bool> hasPar;
        for (vector<int> des : descriptions) {
            if (umap.find(des[0]) == umap.end()) {
                umap[des[0]] = new TreeNode(des[0]);
                hasPar[des[0]] = false;
            }
            if (umap.find(des[1]) == umap.end()) {
                umap[des[1]] = new TreeNode(des[1]);
            }
            hasPar[des[1]] = true;
            if (des[2]) {
                umap[des[0]]->left = umap[des[1]];
            } else {
                umap[des[0]]->right = umap[des[1]];
            }
        }

        for (pair<int, bool> node : hasPar) {
            if (!node.second) {
                return umap[node.first];
            }
        }

        return nullptr;
    }
};

int main() {
    Solution *solution = new Solution();
    cout << "Hello world";
}