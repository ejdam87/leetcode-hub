#include <vector>
#include <algorithm>

class UnionFind
{

    std::vector<int> parent;

public:
    UnionFind(int size)
    {
      
        parent.resize(size);
      
        // Initialize the parent array with each 
        // element as its own representative
        for (int i = 0; i < size; i++) {
            parent[i] = i;
        }
    }

    // Find the representative (root) of the
    // set that includes element i
    int find(int i)
    {
      
        // If i itself is root or representative
        if (parent[i] == i) {
            return i;
        }
      
        // Else recursively find the representative 
        // of the parent
        return find(parent[i]);
    }

    // Unite (merge) the set that includes element 
    // i and the set that includes element j
    void unite(int i, int j)
    {
      
        // Representative of set containing i
        int irep = find(i);
      
        // Representative of set containing j
        int jrep = find(j);
       
        // Make the representative of i's set
        // be the representative of j's set
        parent[irep] = jrep;
    }
};

class Solution
{
public:
    std::vector<int> findRedundantConnection(std::vector<std::vector<int>>& edges)
    {
        int n = -1;

        for ( auto& edge : edges )
        {
            n = std::max( n, edge[0] );
            n = std::max( n, edge[1] );
        }

        auto uf = UnionFind( n );
        std::vector<int> res;
        for ( auto& edge : edges )
        {
            int i = edge[0] - 1;
            int j = edge[1] - 1;
            if ( uf.find( i ) == uf.find( j ) )
            {
                res = edge;
            }
            else
            {
                uf.unite( i, j );
            }
        }

        return res;
    }
};
