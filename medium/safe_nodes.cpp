#include <vector>
#include <algorithm>

int WHITE = 0;
int GRAY = 1;
int BLACK = 2;

int UNKNOWN = 0;
int UNSAFE = 1;
int SAFE = 2;

class Solution
{
private:
    bool isSafe(
        std::vector<std::vector<int>>& graph,
        int node,
        std::vector<int>& colors,
        std::vector<int>& safe,
        std::vector<int>& status)
    {

        bool success = true;
        for ( int succ : graph[node] )
        {
            if ( colors[succ] == GRAY || status[ succ ] == UNSAFE )
            {
                success = false;
            }
            else if ( colors[succ] == WHITE )
            {
                colors[succ] = GRAY;
                if ( !isSafe(graph, succ, colors, safe, status) )
                {
                    success = false;
                }
            }
        }

        if ( success )
        {
            status[ node ] = SAFE;
            safe.push_back( node );
        }
        else
        {
            status[ node ] = UNSAFE;
        }

        colors[node] = BLACK;
        return success;
    }

public:
    std::vector<int> eventualSafeNodes(std::vector<std::vector<int>>& graph)
    {
        std::vector<int> safe;
        std::vector<int> colors;
        std::vector<int> status;
        for (int i = 0; i < graph.size(); i++)
        {
            colors.push_back(WHITE);
            status.push_back(UNKNOWN);
        }

        for ( int i = 0; i < graph.size(); i++ )
        {
            if ( colors[i] == WHITE )
            {
                colors[i] = GRAY;
                isSafe( graph, i, colors, safe, status );
            }
        }

        std::sort( safe.begin(), safe.end() );
        return safe;
    }
};
