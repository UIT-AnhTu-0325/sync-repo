#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
#include <queue>
using namespace std;

//daily-question 2024-05-17
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
    TreeNode *removeLeafNodes(TreeNode *root, int target)
    {
        stack<pair<TreeNode *, TreeNode *>> builder;
        queue<pair<TreeNode *, TreeNode *>> bfs;
        bfs.push({nullptr, root});
        while (!bfs.empty())
        {
            pair<TreeNode *, TreeNode *> top = bfs.front();
            bfs.pop();
            builder.push(top);
            if (top.second->left != nullptr)
            {
                bfs.push({top.second, top.second->left});
            }
            if (top.second->right != nullptr)
            {
                bfs.push({top.second, top.second->right});
            }
        }

        while (!builder.empty())
        {
            pair<TreeNode *, TreeNode *> last = builder.top();
            builder.pop();
            if (last.second->val == target && last.second->left == nullptr && last.second->right == nullptr)
            {
                if (last.first == nullptr)
                    return nullptr;
                if (last.first->left == last.second)
                {
                    last.first->left = nullptr;
                }
                else
                {
                    last.first->right = nullptr;
                }
            }
        }

        return root;
    }
};

int main()
{
    Solution *solution = new Solution();
    cout << "Hello world";
}