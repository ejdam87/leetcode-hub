#include <utility>

struct TreeNode
{
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    std::pair< TreeNode*, bool > lowest_rec(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (root == nullptr)
        {
            return {nullptr, false};
        }
        else if (root == p)
        {
            return {p, false};
        }
        else if (root == q)
        {
            return {q, false};
        }

        auto a = lowest_rec( root -> left, p, q );
        auto b = lowest_rec( root -> right, p, q );

        if (a.second)
        {
            return {a.first, true};
        }
        if (b.second)
        {
            return {b.first, true};
        }

        if ( a.first == p && b.first == q || a.first == q && b.first == p )
        {
            return {root, true};
        }

        if ( a.first == nullptr )
        {
            return b;
        }

        return a;

    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        auto res = lowest_rec(root, p, q);
        return res.first;
    }
};
