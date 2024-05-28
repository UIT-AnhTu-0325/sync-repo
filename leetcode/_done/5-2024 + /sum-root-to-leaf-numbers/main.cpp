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
    int Calc(TreeNode *root, int crr)
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            return crr * 10 + root->val;
        }

        int res = 0;
        crr = crr * 10 + root->val;
        if (root->left != nullptr)
        {
            res += Calc(root->left, crr);
        }
        if (root->right != nullptr)
        {
            res += Calc(root->right, crr);
        }
        return res;
    }

    int sumNumbers(TreeNode *root)
    {
        return Calc(root, 0);
    }
};
int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}