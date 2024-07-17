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

// daily-question 2024-07-17
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
   public:
    void solve(TreeNode *root, TreeNode *parent, vector<TreeNode *> &res,
               vector<int> &to_delete) {
        if (root == nullptr) return;
        bool isDelete = false;
        for (int del : to_delete) {
            if (del == root->val) {
                isDelete = true;
                break;
            }
        }

        if (!isDelete) {
            if (parent == nullptr) {
                res.push_back(root);
            }
            solve(root->left, root, res, to_delete);
            solve(root->right, root, res, to_delete);
        }

        if (isDelete) {
            if (parent != nullptr) {
                if (parent->left != nullptr && parent->left->val == root->val) {
                    parent->left = nullptr;
                }
                if (parent->right != nullptr &&
                    parent->right->val == root->val) {
                    parent->right = nullptr;
                }
            }

            solve(root->left, nullptr, res, to_delete);
            solve(root->right, nullptr, res, to_delete);
        }
    }
    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete) {
        vector<TreeNode *> res;
        solve(root, nullptr, res, to_delete);
        return res;
    }
};

int main() {
    Solution *solution = new Solution();
    TreeNode *root =
        new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)),
                     new TreeNode(3, new TreeNode(6), new TreeNode(7)));
    vector<int> to_delete = {3, 5};
    solution->delNodes(root, to_delete);
    cout << "Hello world";
}