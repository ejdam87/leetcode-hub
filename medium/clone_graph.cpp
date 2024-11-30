#include <vector>
#include <unordered_map>

class Node
{
public:
    int val;
    std::vector<Node*> neighbors;

    Node()
    {
        val = 0;
        neighbors = std::vector<Node*>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = std::vector<Node*>();
    }
    Node(int _val, std::vector<Node*> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
private:
    void explore(Node* node, std::unordered_map<int, std::vector<int>>& id_map)
    {
        for ( Node* succ : node -> neighbors )
        {
            id_map[ node -> val ].push_back( succ -> val );
            if ( !id_map.contains( succ -> val ) )
            {
                id_map[ succ -> val ] = {};
                explore( succ, id_map );
            }
        }
    }

public:
    Node* cloneGraph(Node* node)
    {

        if (node == nullptr)
        {
            return nullptr;
        }

        std::unordered_map<int, std::vector<int>> id_map = {};
        id_map[node -> val] = {};
        explore(node, id_map);
        std::unordered_map<int, Node*> clones = {};

        for ( auto& [id, succs] : id_map )
        {
            clones[id] = new Node( id );
        }

        for ( auto& [id, succs] : id_map )
        {
            for ( int succ_id : succs )
            {
                clones[id] -> neighbors.push_back( clones[succ_id] );
            }
        }

        return clones[ node -> val ];
    }
};
