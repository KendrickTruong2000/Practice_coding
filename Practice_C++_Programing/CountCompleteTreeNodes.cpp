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

int countNodes(TreeNode *);
int count(TreeNode *);
// vector<int> inorderTraversal(TreeNode *);

int main(int argc, char const *argv[])
{
    TreeNode *node6 = new TreeNode(6);
    TreeNode *node3 = new TreeNode(3, node6, nullptr);
    TreeNode *node4 = new TreeNode(4);
    TreeNode *node5 = new TreeNode(5);
    TreeNode *node2 = new TreeNode(2, node4, node5);
    TreeNode *node1 = new TreeNode(1, node2, node3);
    int result = countNodes(node1);

    cout << result << endl;

    return 0;
}

// vector<int> inorderTraversal(TreeNode *root)
// {
//     vector<int> result;

//     if (root == nullptr)
//     {
//         return result;
//     }

//     vector<int> left = inorderTraversal(root->left);
//     result.insert(result.end(), left.begin(), left.end());

//     result.push_back(root->val);

//     vector<int> right = inorderTraversal(root->right);
//     result.insert(result.end(), right.begin(), right.end());

//     return result;
// }

// int countNodes(TreeNode *root)
// {
//     int count = 0;
//     vector<int> temp;

//     if (root == nullptr)
//     {
//         return count;
//     }

//     vector<int> left = inorderTraversal(root->left);
//     temp.insert(temp.end(), left.begin(), left.end());

//     temp.push_back(root->val);

//     vector<int> right = inorderTraversal(root->right);
//     temp.insert(temp.end(), right.begin(), right.end());

//     return temp.size();
// }

int count(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    return 1 + count(root->left) + count(root->right);    
}

int countNodes(TreeNode *root)
{
    return count(root);
}