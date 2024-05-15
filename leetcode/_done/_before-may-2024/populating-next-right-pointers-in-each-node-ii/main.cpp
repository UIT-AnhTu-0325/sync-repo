#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (root == nullptr)
            return root;

        root->next = nullptr;

        vector<Node *> vecPar = {root};
        vector<Node *> vecChild;
        while (true)
        {
            if (vecPar.size() == 0)
                break;

            for (int i = 0; i < vecPar.size(); i++)
            {
                if (vecPar[i]->left != nullptr)
                    vecChild.push_back(vecPar[i]->left);
                if (vecPar[i]->right != nullptr)
                    vecChild.push_back(vecPar[i]->right);
            }

            vecPar = vecChild;
            int n = vecChild.size();

            for (int i = 0; i < n; i++)
            {
                if (i == n - 1)
                {
                    vecChild[i]->next = nullptr;
                }
                else
                {

                    vecChild[i]->next = vecChild[i + 1];
                }
            }

            vecChild.clear();
        }

        return root;
    }
};

int main()
{
    Solution *solution = new Solution();

    Node *a4 = new Node(4);
    Node *a5 = new Node(5);
    Node *a2 = new Node(2, a4, a5, nullptr);
    Node *a3 = new Node(3, nullptr, new Node(7), nullptr);
    Node *a1 = new Node(1, a2, a3, nullptr);

    solution->connect(a1);

    cout << "Hello world";
}