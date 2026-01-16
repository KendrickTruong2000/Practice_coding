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

int minDepth(TreeNode *root);
int min(int leftDepth, int rightDepth);

int main(int argc, char const *argv[])
{
    TreeNode *node5 = new TreeNode(7);
    TreeNode *node4 = new TreeNode(15);
    TreeNode *node3 = new TreeNode(20, node4, node5);
    TreeNode *node2 = new TreeNode(9);
    TreeNode *node1 = new TreeNode(3, node2, node3);

    int result = minDepth(node1);
    cout << result << endl;

    return 0;
}

int minDepth(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    if (root->left == nullptr && root->right == nullptr)
    {
        return 1;
    }

    if (root->left == nullptr)
    {
        return 1 + minDepth(root->right);
    }

    if (root->right == nullptr)
    {
        return 1 + minDepth(root->left);
    }

    return 1 + min(minDepth(root->left), minDepth(root->right));
}

int min(int leftDepth, int rightDepth)
{
    if (leftDepth < rightDepth)
    {
        return leftDepth;
    }
    else
    {
        return rightDepth;
    }
}