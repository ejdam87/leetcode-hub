
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution
{
public:
    TreeNode* invertTree(TreeNode* root)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        TreeNode* a = invertTree(root -> right);
        TreeNode* b = invertTree(root -> left);

        root -> left = a;
        root -> right = b;
        return root;
    }
};