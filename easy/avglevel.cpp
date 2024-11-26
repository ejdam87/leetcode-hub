#include <vector>

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
private:
    void levels( TreeNode* node, int depth, std::vector< std::vector<int> >& ls )
    {
        if (node == nullptr)
        {
            return;
        }

        if (ls.size() <= depth)
        {
            ls.push_back( {} );
        }

        ls[depth].push_back(node -> val);

        levels( node -> left, depth + 1, ls );
        levels( node -> right, depth + 1, ls );
    }

public:
    std::vector<double> averageOfLevels(TreeNode* root)
    {
        std::vector< std::vector<int> > ls = {};
        levels(root, 0, ls);

        std::vector<double> means = {};

        for ( auto& level : ls )
        {
            double s = 0;
            for (int val : level)
            {
                s += val;
            }
            means.push_back( s / level.size() );
        }
        return means;
    }
};
