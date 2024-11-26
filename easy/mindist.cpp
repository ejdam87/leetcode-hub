#include <cstdint>
#include <algorithm>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    int getMax(TreeNode* root)
    {
        if (root == nullptr)
        {
            return -1;
        }

        while (root -> right != nullptr)
        {
            root = root -> right;
        }

        return root -> val;
    }


    int getMin(TreeNode* root)
    {
        if (root == nullptr)
        {
            return -1;
        }

        while (root -> left != nullptr)
        {
            root = root -> left;
        }

        return root -> val;
    }

public:
    int getMinimumDifference(TreeNode* root)
    {
        if (root == nullptr)
        {
            return INT32_MAX;
        }

        int best = INT32_MAX;
        if (root -> left != nullptr)
        {
            best = std::min( best, std::abs( getMax(root -> left) - root -> val ) );
        }
        if (root -> right != nullptr)
        {
            best = std::min( best, std::abs( getMin(root -> right) - root -> val ) );
        }

        best = std::min( best, getMinimumDifference(root -> left) );
        best = std::min( best, getMinimumDifference(root -> right) );

        return best;
    }
};
