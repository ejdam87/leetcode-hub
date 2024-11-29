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

class BSTIterator {
private:

    std::vector<int> arr;
    int i;

    std::vector<int> strdArray(TreeNode* node)
    {
        if (node == nullptr)
        {
            return {};
        }

        std::vector<int> l = strdArray(node -> left);
        l.push_back(node -> val);
        std::vector<int> r = strdArray(node -> right);
        l.insert(l.end(), r.begin(), r.end());
        return l;
    }

public:

    BSTIterator(TreeNode* root)
    {
        arr = strdArray(root);
        i = -1;
    }

    int next()
    {
        i++;
        return arr[i];
    }
    
    bool hasNext()
    {
        if (i == -1)
        {
            return true;
        }

        return i < arr.size() - 1;
    }
};

int main()
{
    TreeNode* r = new TreeNode(1);
    BSTIterator bit = BSTIterator(r);
    bool val = bit.hasNext();
}
