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

bool isSymmetric(TreeNode *root);
bool isMirror(TreeNode *rootLeft, TreeNode *rootRight);

int main(int argc, char const *argv[])
{
    // TreeNode *node1 = new TreeNode(4, nullptr, nullptr);
    // TreeNode *node2 = new TreeNode(3, nullptr, nullptr);
    // TreeNode *node3 = new TreeNode(2, node1, node2);

    // TreeNode *node6 = new TreeNode(3, nullptr, nullptr);
    // TreeNode *node7 = new TreeNode(4, nullptr, nullptr);
    // TreeNode *node5 = new TreeNode(2, node6, node7);
    // TreeNode *node4 = new TreeNode(1, node3, node5);

    TreeNode *node2 = new TreeNode(2, nullptr, nullptr);
    TreeNode *node3 = new TreeNode(3, nullptr, nullptr);
    TreeNode *node1 = new TreeNode(1, node2, node3);

    bool result = isSymmetric(node1);

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

bool isSymmetric(TreeNode *root)
{
    if (root == nullptr)
    {
        return true;
    }

    return isMirror(root->left, root->right);
}

bool isMirror(TreeNode *left, TreeNode *right)
{
    if (left == nullptr && right == nullptr)
    {
        return true;
    }

    if (left == nullptr || right == nullptr)
    {
        return false;
    }

    return (left->val == right->val) &&
           isMirror(left->left, right->right) &&
           isMirror(left->right, right->left);
}
