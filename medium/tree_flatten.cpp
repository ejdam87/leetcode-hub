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
    TreeNode* flattenRec(TreeNode* node)
    {
        if (node == nullptr)
        {
            return nullptr;
        }

        TreeNode* l1 = flattenRec(node -> left);
        TreeNode* l2 = flattenRec(node -> right);

        node -> left = nullptr;
        node -> right = l1;
        if (l1 == nullptr)
        {
            node -> right = l2;
            return node;
        }

        TreeNode* lst = l1;
        while (lst -> right != nullptr)
        {
            lst = lst -> right;
        }
        lst -> right = l2;
    }

public:
    void flatten(TreeNode* root)
    {
        flattenRec(root);
    }
};
