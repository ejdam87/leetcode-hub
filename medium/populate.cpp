#include <vector>

class Node
{
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
private:
    void levels( Node* node, int depth, std::vector< std::vector<Node*> >& ls )
    {
        if (node == nullptr)
        {
            return;
        }

        if (ls.size() <= depth)
        {
            ls.push_back( {} );
        }

        ls[depth].push_back(node);

        levels( node -> left, depth + 1, ls );
        levels( node -> right, depth + 1, ls );
    }
public:
    Node* connect(Node* root)
    {
        std::vector< std::vector<Node*> > ls = {};
        levels(root, 0, ls);
        for ( auto& level : ls )
        {
            for (int i = 0; i < level.size() - 1; i++)
            {
                level[i] -> next = level[i + 1];
            }
        }

        return root;
    }
};

int main()
{
    Node* root = new Node(5);
    Solution().connect(root);
}