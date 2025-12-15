#include <iostream>
#include <vector>

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

int maxDepth(TreeNode *root);
int max(int leftDepth, int rightDepth);

int main(int argc, char const *argv[])
{
    TreeNode *node5 = new TreeNode(7, nullptr, nullptr);
    TreeNode *node4 = new TreeNode(15, nullptr, nullptr);
    TreeNode *node3 = new TreeNode(20, node4, node5);
    TreeNode *node2 = new TreeNode(9, nullptr, nullptr);
    TreeNode *node1 = new TreeNode(3, node2, node3);
    int result = maxDepth(node1);
    cout << result << endl;

    return 0;
}

int maxDepth(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return 1 + max(leftDepth, rightDepth);
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