#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    string solver(TreeNode *root, string crr)
    {
        string res = crr;

        if (root == nullptr)
            return res;

        if (root->left == nullptr && root->right == nullptr)
        {
            res = char(root->val + 97) + res;
            return res;
        }

        res = char(root->val + 97) + res;

        string left = solver(root->left, res);
        string right = solver(root->right, res);

        if (root->right == nullptr)
        {
            return left;
        }
        if (root->left == nullptr)
        {
            return right;
        }

        return lexicographical_compare(left.begin(), left.end(), right.begin(), right.end())
                   ? left
                   : right;
    }

    string smallestFromLeaf(TreeNode *root)
    {
        return solver(root, "");
    }
};

int main()
{
    TreeNode *input =
        new TreeNode(
            25,
            new TreeNode(1,
                         new TreeNode(0,
                                      new TreeNode(1, new TreeNode(0), nullptr), nullptr),
                         new TreeNode(0)),
            nullptr);
    Solution *solution = new Solution();
    solution->smallestFromLeaf(input);
    string left = "ba";
    string right = "b";
    bool s = lexicographical_compare(left.begin(), left.end(), right.begin(), right.end());
    cout << "Hello world";
}