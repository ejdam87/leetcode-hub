
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

    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        if (p == nullptr)
        {
            return q == nullptr;
        }
        if (q == nullptr)
        {
            return p == nullptr;
        }

        return p -> val == q -> val && isSameTree(p -> left, q -> left) && isSameTree(p -> right, q -> right);
    }

    bool isSymmetric(TreeNode* root)
    {
        if (root == nullptr)
        {
            return true;
        }

        if (root -> right == nullptr && root -> left == nullptr)
        {
            return true;
        }
        else if (root -> right == nullptr)
        {
            return false;
        }

        invertTree(root -> right);
        return isSameTree( root -> left, root -> right );
    }
};
