#include <iostream>

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

bool isBalanceTree(TreeNode *root);
int height(TreeNode *root);
int max(int leftDepth, int rightDepth);

int main(int argc, char const *argv[])
{
    TreeNode *node5 = new TreeNode(7);
    TreeNode *node4 = new TreeNode(15);
    TreeNode *node3 = new TreeNode(20, node4, node5);
    TreeNode *node2 = new TreeNode(9);
    TreeNode *node1 = new TreeNode(3, node2, node3);
    bool result = isBalanceTree(node1);

    if (result == 1)
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    delete node5;
    delete node4;
    delete node3;
    delete node2;
    delete node1;

    return 0;
}

int max(int leftDepth, int rightDepth)
{
    if (leftDepth >= rightDepth)
    {
        return leftDepth;
    }
    else
    {
        return rightDepth;
    }
}

int height(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int leftHeight = height(root->left);
    if (leftHeight == -1)
    {
        return -1;
    }

    int rightHeight = height(root->right);
    if (rightHeight == -1)
    {
        return -1;
    }

    if (abs(leftHeight - rightHeight) > 1)
    {
        return -1;
    }

    return 1 + max(leftHeight, rightHeight);
}

bool isBalanceTree(TreeNode *root)
{
    return height(root) != -1;
}