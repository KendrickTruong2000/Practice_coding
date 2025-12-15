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

bool isSameTree(TreeNode *p, TreeNode *q);

int main(int argc, char const *argv[])
{
    TreeNode *p2 = new TreeNode(2, nullptr, nullptr);
    TreeNode *p3 = new TreeNode(3, nullptr, nullptr);
    TreeNode *p1 = new TreeNode(1, p2, p3);

    TreeNode *q2 = new TreeNode(2, nullptr, nullptr);
    TreeNode *q3 = new TreeNode(3, nullptr, nullptr);
    TreeNode *q1 = new TreeNode(1, p2, p3);

    bool result = isSameTree(p1, q1);

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

bool isSameTree(TreeNode *p, TreeNode *q)
{
    if (p == nullptr && q == nullptr)
    {
        return true;
    }

    if (p == nullptr || q == nullptr)
    {
        return false;
    }

    if (p->val != q->val)
    {
        return false;
    }

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
