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
private:
    void levels( TreeNode* node, int depth, std::vector< int >& ls )
    {
        if (node == nullptr)
        {
            return;
        }

        if (ls.size() <= depth)
        {
            ls.push_back( -1 );
        }

        ls[depth] = node -> val;

        levels( node -> left, depth + 1, ls );
        levels( node -> right, depth + 1, ls );
    }

public:
    std::vector<int> rightSideView(TreeNode* root)
    {
        std::vector<int> ls = {};
        levels(root, 0, ls);
        return ls;
    }
};

void printVector(std::vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << ' ' << v[i] << ' ';
    }
    std::cout << '\n';
}

int main()
{
    TreeNode root = TreeNode(1);
    TreeNode n1 = TreeNode(1);
    TreeNode n2 = TreeNode(2);
    TreeNode n3 = TreeNode(3);
    TreeNode n4 = TreeNode(4);
    root.left = &n1;
    root.right = &n2;
    n2.right = &n3;
    n1.left = &n4;

    printVector( Solution().rightSideView(&root) );

}
