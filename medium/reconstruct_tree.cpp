#include <vector>
#include <unordered_set>

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
    TreeNode* buildRec(std::vector<int>& preorder, std::vector<int>& inorder, int i, int j)
    {
        if (i > j)
        {
            return nullptr;
        }

        if (i == j)
        {
            return new TreeNode( preorder[i] );
        }

        TreeNode* node = new TreeNode( preorder[i] );
        int preceeding = 0;

        std::unordered_set<int> after = {};
        for (int l = i + 1; l < preorder.size(); l++)
        {
            after.insert( preorder[l] );
        }

        // TODO: how many are preceeding in inorder that are after in preorder ?
        for (int k = 0; k <= preorder.size(); k++)
        {
            if (inorder[k] == preorder[i])
            {
                break;
            }

            if ( after.find( inorder[k] ) != after.end() )
            {
                preceeding++;
            }
        }

        node -> left = buildRec(preorder, inorder, i + 1, i + preceeding);
        node -> right = buildRec(preorder, inorder, i + preceeding + 1, j);
        return node;
    }

public:
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder)
    {
        return buildRec(preorder, inorder, 0, preorder.size() - 1);
    }
};

int main()
{
    std::vector<int> preorder = {3,9,20,15,7};
    std::vector<int> inorder = {9,3,15,20,7};
    TreeNode* res = Solution().buildTree(preorder, inorder);
}