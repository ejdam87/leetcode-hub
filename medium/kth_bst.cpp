#include <vector>
#include <iostream>

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
    void fstK(TreeNode* node, std::vector<int>& vals, int k)
    {
        if (node == nullptr)
        {
            return;
        }

        fstK(node -> left, vals, k);
        if (vals.size() == k)
        {
            return;
        }

        vals.push_back( node -> val );
        if (vals.size() == k)
        {
            return;
        }

        fstK(node -> right, vals, k);
    }

    int kthSmallest(TreeNode* root, int k)
    {
        std::vector<int> vals = {};
        fstK(root, vals, k);
        return vals[ vals.size() - 1 ];
    }
};

int main()
{
    TreeNode n1 = TreeNode(1);
    TreeNode n2 = TreeNode(2);
    TreeNode n3 = TreeNode(3);
    TreeNode n4 = TreeNode(4);
    TreeNode n5 = TreeNode(5);

    n3.left = &n2;
    n2.left = &n1;
    n3.right = &n4;
    n4.right = &n5;

    std::cout << Solution().kthSmallest(&n3, 1) << '\n';

}