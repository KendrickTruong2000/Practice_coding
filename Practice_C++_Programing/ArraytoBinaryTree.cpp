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

TreeNode *sortedArrayToBST(vector<int> &);
TreeNode *buildBST(vector<int> &, int, int);
vector<int> inorderTraversal(TreeNode *root);

int main(int argc, char const *argv[])
{
    vector<int> nums = {-10, -3, 0, 5, 9};
    vector<int> vec;
    TreeNode *result = sortedArrayToBST(nums);
    vec = inorderTraversal(result);

    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;

    return 0;
}

TreeNode *sortedArrayToBST(vector<int> &nums)
{
    return buildBST(nums, 0, (int)nums.size() - 1);
}

TreeNode *buildBST(vector<int> &nums, int left, int right)
{
    if (left > right)
    {
        return nullptr;
    }

    int mid = left + (right - left) / 2;
    TreeNode *root = new TreeNode(nums[mid]);
    root->left = buildBST(nums, left, mid - 1);
    root->right = buildBST(nums, mid + 1, right);

    return root;
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