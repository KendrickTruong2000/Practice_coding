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

TreeNode *invertTree(TreeNode *);

int main(int argc, char const *argv[])
{
    TreeNode *node9 = new TreeNode(9);
    TreeNode *node6 = new TreeNode(6);
    TreeNode *node3 = new TreeNode(3);
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node7 = new TreeNode(7, node6, node9);
    TreeNode *node2 = new TreeNode(2, node1, node2);
    TreeNode *node4 = new TreeNode(4, node2, node7);
    TreeNode *result = invertTree(node4);

    return 0;
}

TreeNode *invertTree(TreeNode *root)
{
    if (!root)
    {
        return nullptr;
    }

    swap(root->left, root->right);
    invertTree(root->left);
    invertTree(root->right);

    return root;
}