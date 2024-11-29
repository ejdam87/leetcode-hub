#include <vector>

class Node
{
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val)
    {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};


class Solution {
private:
    int getRandIndex( Node* head, Node* node )
    {
        if (node -> random == nullptr)
        {
            return -1;
        }

        int i = 0;
        for (Node* it = head; it != nullptr; it = it -> next)
        {
            if (it == node -> random)
            {
                return i;
            }
            i++;
        }

        return -1;
    }

public:
    Node* copyRandomList(Node* head)
    {
        if (head == nullptr)
        {
            return nullptr;
        }

        std::vector<Node*> copied = {};

        for (Node* it = head; it != nullptr; it = it -> next)
        {
            copied.push_back( new Node( it -> val ) );
        }

        std::vector<int> indices = {};

        for (Node* it = head; it != nullptr; it = it -> next)
        {
            indices.push_back( getRandIndex(head, it) );
        }

        for (int i = 0; i < copied.size() - 1; i++)
        {
            copied[i] -> next = copied[i + 1];

            if (indices[i] != -1)
            {
                copied[i] -> random = copied[ indices[i] ];
            }
        }

        if (indices[copied.size() - 1] != -1)
        {
            copied[ copied.size() - 1 ] -> random = copied[ indices[ copied.size() - 1 ] ];
        }

        return copied[0];
    }
};

int main()
{
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);

    n1 -> next = n2;
    n2 -> next = n3;
    n3 -> next = n4;
    n4 -> next = n5;
}
