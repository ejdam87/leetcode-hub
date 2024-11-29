#include <algorithm>
#include <utility>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    std::pair<std::pair<int, int>, int> maxPathSumRec(TreeNode* root)
    {
        if (root == nullptr)
        {
            return { {-1001, -1001}, -1001 };
        }

        auto a = maxPathSumRec( root -> left );
        auto b = maxPathSumRec( root -> right );

        int direct;
        if (a.first.first <= 0 && b.first.first <= 0)
        {
            direct = root -> val;
        }
        else
        {
            direct = root -> val + std::max(a.first.first, b.first.first);
        }

        int bent = a.first.first + b.first.first + root -> val;

        std::vector<int> vals = {bent, direct, a.second, b.second};
        int best = *std::max_element(vals.begin(), vals.end());

        return {{direct, bent}, best};
    }

    int maxPathSum(TreeNode* root)
    {
        auto res = maxPathSumRec(root);
        return res.second;
    }
};

int main()
{
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);
    n1 -> left = n2;
    n1 -> right = n3;

    Solution().maxPathSum(n1);
}
