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

vector<int> preorederTraversal(TreeNode *root);
vector<int> postorderTraversal(TreeNode *root);

int main(int argc, char const *argv[])
{
    TreeNode *node7 = new TreeNode(7);
    TreeNode *node6 = new TreeNode(6);
    TreeNode *node5 = new TreeNode(5, node6, node7);
    TreeNode *node4 = new TreeNode(4);
    TreeNode *node2 = new TreeNode(2, node4, node5);
    TreeNode *node9 = new TreeNode(9);
    TreeNode *node8 = new TreeNode(8, node9, nullptr);
    TreeNode *node3 = new TreeNode(3, nullptr, node8);
    TreeNode *node1 = new TreeNode(1, node2, node3);

    // vector<int> result = preorederTraversal(node1);
    vector<int> result = postorderTraversal(node1);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}

vector<int> preorederTraversal(TreeNode *root)
{
    vector<int> result;

    if (root == nullptr)
    {
        return result;
    }

    stack<TreeNode *> st;
    st.push(root);

    while (!st.empty())
    {
        TreeNode *node = st.top();
        st.pop();

        result.push_back(node->val);

        if (node->right)
        {
            st.push(node->right);
        }

        if (node->left)
        {
            st.push(node->left);
        }
    }

    return result;
}

vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> result;

    if (root == nullptr)
    {
        return result;
    }

    stack<TreeNode *> st1;
    stack<TreeNode *> st2;

    st1.push(root);

    while (!st1.empty())
    {
        TreeNode *node = st1.top();
        st1.pop();

        st2.push(node);

        if (node->left)
        {
            st1.push(node->left);
        }

        if (node->right)
        {
            st1.push(node->right);
        }
    }

    while (!st2.empty())
    {
        result.push_back(st2.top()->val);
        st2.pop();
    }

    return result;
}