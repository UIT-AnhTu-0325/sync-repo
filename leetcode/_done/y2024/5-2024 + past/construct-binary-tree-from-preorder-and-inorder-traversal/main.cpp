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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (preorder.size() == 0)
            return nullptr;
        int rootVal = preorder[0];
        TreeNode *root = new TreeNode(preorder[0]);
        vector<int> leftInorder;
        vector<int> rightInorder;
        vector<int> leftPreorder;
        vector<int> rightPreorder;
        int i = 0;
        int cLeft = 0;
        int cRight = 0;
        while (inorder[i] != rootVal && i < inorder.size())
        {
            leftInorder.push_back(inorder[i]);
            cLeft++;
            i++;
        }
        i++;
        while (i < inorder.size())
        {
            rightInorder.push_back(inorder[i]);
            cRight++;
            i++;
        }
        int j = 1;
        for (j; j < cLeft + 1; j++)
        {
            leftPreorder.push_back(preorder[j]);
        }
        for (j; j < preorder.size(); j++)
        {
            rightPreorder.push_back(preorder[j]);
        }
        root->left = buildTree(leftPreorder, leftInorder);
        root->right = buildTree(rightPreorder, rightInorder);
        return root;
    }
};

int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}