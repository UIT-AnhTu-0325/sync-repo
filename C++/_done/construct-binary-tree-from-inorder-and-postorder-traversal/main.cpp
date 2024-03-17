#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
using namespace std;

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.size() == 0)
            return nullptr;
        int rootVal = postorder[postorder.size()-1];
        TreeNode *root = new TreeNode(rootVal);

        vector<int> leftinOrder;
        vector<int> rightinOrder;
        vector<int> leftPostOrder;
        vector<int> rightPostOrder;

        int i = 0;
        while (inorder[i] != rootVal && i < inorder.size())
        {
            leftinOrder.push_back(inorder[i]);
            i++;
        }
        i++;
        while(i < inorder.size()){
            rightinOrder.push_back(inorder[i]);
            i++;
        }

        int j = 0;
        for(j; j< leftinOrder.size(); j++){
            leftPostOrder.push_back(postorder[j]);
        }
        for(j; j < postorder.size() -1 ; j ++){
            rightPostOrder.push_back(postorder[j]);
        }

        root->left = buildTree(leftinOrder, leftPostOrder);
        root->right = buildTree(rightinOrder, rightPostOrder);

        return root;
    }
};

int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}