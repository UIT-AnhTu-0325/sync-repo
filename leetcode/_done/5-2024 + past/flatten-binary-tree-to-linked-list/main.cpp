#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
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
    void flatten(TreeNode *root)
    {
        if (root == nullptr)
            return;
        TreeNode *right = root->right;
        flatten(root->right);

        TreeNode *left = root->left;
        flatten(root->left);

        root->left = nullptr;
        root->right = left;
        while (root->right != nullptr)
        {
            root = root->right;
        }
        root->right = right;
    }
};

int main()
{
    Solution *solution = new Solution();

    TreeNode *a3 = new TreeNode(3);
    TreeNode *a4 = new TreeNode(4);
    TreeNode *a2 = new TreeNode(2, a3, a4);
    TreeNode *a6 = new TreeNode(6);
    TreeNode *a5 = new TreeNode(5, nullptr, a6);
    TreeNode *a1 = new TreeNode(1, a2, a5);

    solution->flatten(a1);

    cout << "Hello world";
}