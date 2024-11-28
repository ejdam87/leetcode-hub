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
    TreeNode* buildRec(std::vector<int>& postorder, std::vector<int>& inorder, int i, int j)
    {
        if (i > j)
        {
            return nullptr;
        }

        if (i == j)
        {
            return new TreeNode( postorder[j] );
        }

        TreeNode* node = new TreeNode( postorder[j] );
        int suceeding = 0;

        std::unordered_set<int> before = {};
        for (int l = j - 1; l >= 0; l--)
        {
            before.insert( postorder[l] );
        }

        for (int k = postorder.size() - 1; k >= 0; k--)
        {
            if (inorder[k] == postorder[j])
            {
                break;
            }

            if ( before.find( inorder[k] ) != before.end() )
            {
                suceeding++;
            }
        }

        node -> left = buildRec(postorder, inorder, i, j - suceeding - 1);
        node -> right = buildRec(postorder, inorder, j - suceeding, j - 1);
        return node;
    }

public:
    TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder)
    {
        return buildRec(postorder, inorder, 0, postorder.size() - 1);
    }
};

int main()
{
    std::vector<int> postorder = {9,15,7,20,3};
    std::vector<int> inorder = {9,3,15,20,7};
    TreeNode* res = Solution().buildTree(inorder, postorder);
}