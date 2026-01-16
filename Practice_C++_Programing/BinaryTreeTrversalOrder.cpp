#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr)
    {
    }
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x),
                                                       left(left),
                                                       right(right) {}
};

vector<int> inorderTraversal(TreeNode *root);

int main(int argc, char const *argv[])
{
    TreeNode *node3 = new TreeNode(2, nullptr, nullptr);
    TreeNode *node2 = new TreeNode(3, node3, nullptr);
    TreeNode *node1 = new TreeNode(1, nullptr, node2);
    vector<int> result = inorderTraversal(node1);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    delete node3;
    delete node2;
    delete node1;

    return 0;
}

vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> result;

    if (root == nullptr)
    {
        return result;
    }

    vector<int> left = inorderTraversal(root->left);
    result.insert(result.end(), left.begin(), left.end());

    result.push_back(root->val);

    vector<int> right = inorderTraversal(root->right);
    result.insert(result.end(), right.begin(), right.end());

    return result;
}
