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
    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {
        if(root == nullptr) return nullptr;
        if (depth == 2)
        {
            TreeNode *nLeft = new TreeNode(val, root->left, nullptr);
            TreeNode *nRight = new TreeNode(val, nullptr, root->right);
            root->left = nLeft;
            root->right = nRight;
            return root;
        }
        else if (depth == 1)
        {
            return new TreeNode(val, root, nullptr);
        }
        root->left = addOneRow(root->left, val, depth - 1);
        root->right = addOneRow(root->right, val, depth - 1);

        return root;
    }
};

int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}