#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void dfs(TreeNode *node, string path, vector<string> &result);
vector<string>binaryTreePath(TreeNode *);

int main(int argc, char const *argv[])
{
    TreeNode *node5 = new TreeNode(5);
    TreeNode *node2 = new TreeNode(2, nullptr, node5);
    TreeNode *node3 = new TreeNode(3);
    TreeNode *node1 = new TreeNode(1, node2, node3);
    vector<string> result = binaryTreePath(node1);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    
    return 0;
}

vector<string> binaryTreePath(TreeNode *root)
{
    vector<string> result;

    if (root == nullptr)
    {
        return result;
    } 
    
    dfs(root, "", result);

    return result;
}

void dfs(TreeNode *node, string path, vector<string> &result)
{
    if (!node)
    {
        return;
    }

    path += to_string(node->val);

    if (!node->left && !node->right)
    {
        result.push_back(path);
        return;
    }
    
    path += "->";

    dfs(node->left, path, result);
    dfs(node->right, path, result);
}