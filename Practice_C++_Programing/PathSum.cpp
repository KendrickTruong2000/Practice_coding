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

bool hasPathSum(TreeNode *root, int target);

int main(int argc, char const *argv[])
{
    TreeNode *node9 = new TreeNode(2);
    TreeNode *node8 = new TreeNode(7);
    TreeNode *node7 = new TreeNode(11, node8, node9);
    TreeNode *node6 = new TreeNode(1);
    TreeNode *node5 = new TreeNode(4, nullptr, node6);
    TreeNode *node4 = new TreeNode(13);
    TreeNode *node3 = new TreeNode(8, node4, node5);
    TreeNode *node2 = new TreeNode(4, node7, nullptr);
    TreeNode *node1 = new TreeNode(5, node2, node3);
    int target = 22;
    bool result = hasPathSum(node1, target);

    if (result == 1)
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    return 0;
}

bool hasPathSum(TreeNode *root, int target)
{
    if (root == nullptr)
    {
        return false;
    }

    if (root->left == nullptr && root->right == nullptr)
    {
        return root->val == target;
    }

    int remaining = target - root->val;

    return hasPathSum(root->left, remaining) || hasPathSum(root->right, remaining);
}