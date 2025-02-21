struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class FindElements
{
    private:
        TreeNode* rt;
    public:
        FindElements(TreeNode* root)
        {
            rt = root;
            restoreTree(rt, 0);
        }

        void restoreTree(TreeNode* node, int val)
        {
            if ( node == nullptr )
            {
                return;
            }
            node -> val = val;
            restoreTree(node -> left, 2 * val + 1);
            restoreTree(node -> right, 2 * val + 2);
        }
        
        bool findRec(TreeNode* node, int target)
        {
            if ( node == nullptr )
            {
                return false;
            }
            else if ( node -> val == target )
            {
                return true;
            }
            return findRec(node -> left, target) || findRec(node -> right, target);
        }

        bool find(int target)
        {
            return findRec(rt, target);
        }
};
