#include <vector>
#include <algorithm>
#include <unordered_set>
#include <queue>

const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;

class Solution
{
private:
    void component_of(
            std::vector<std::vector<int>>& gcomps,
            std::vector<std::unordered_set<int>>& components,
            int start
        )
    {
        std::queue<int> q;
        std::unordered_set<int> visited;
        visited.insert( start );
        q.push( start );

        while ( !q.empty() )
        {
            int v = q.front();
            q.pop();

            for ( int succ : gcomps[ v ] )
            {
                if ( !visited.contains( succ ) )
                {
                    visited.insert( succ );
                    components[ start ].insert( succ );
                    q.push( succ );
                }
            }
        }
    }

    bool topoSort(
            std::vector<std::vector<int>>& g,
            int v,
            std::vector<int>& colors,
            std::vector<int>& ordered
        )
    {

        for (int succ : g[v])
        {
            if (colors[succ] == GRAY)
            {
                return false;
            }

            else if (colors[succ] == WHITE)
            {
                colors[succ] = GRAY;
                int acyclic = topoSort(g, succ, colors, ordered);
                if (!acyclic)
                {
                    return false;
                }
            }
        }

        colors[v] = BLACK;
        ordered.push_back(v);
        return true;
    }
public:
    std::vector<bool> checkIfPrerequisite(
            int numCourses,
            std::vector<std::vector<int>>& prerequisites,
            std::vector<std::vector<int>>& queries
        )
    {
        std::vector<std::vector<int>> g = {};
        std::vector<int> colors = {};
        std::vector< std::unordered_set<int> > components;
        for (int i = 0; i < numCourses; i++)
        {
            g.push_back({});
            colors.push_back(WHITE);
            components.push_back( {} );
        }

        for (auto& prereq : prerequisites)
        {
            g[ prereq[0] ].push_back( prereq[1] );
        }

        for ( int i = 0; i < numCourses; i++ )
        {
            component_of( g, components, i );
        }

        std::vector<int> topo = {};
        for ( int v = 0; v < numCourses; v++ )
        {
            if (colors[v] == WHITE)
            {
                colors[v] = GRAY;
                int acyclic = topoSort(g, v, colors, topo);
                if (!acyclic)
                {
                    return {};  // assuming no cycles
                }
            }
        }

        std::reverse(topo.begin(), topo.end());
        std::vector<int> indices = std::vector<int>(numCourses, -1);

        for ( int i = 0; i < numCourses; i++ )
        {
            indices[ topo[i] ] = i;
        }

        std::vector<bool> res;

        for ( auto& q : queries )
        {
            int u = q[0];
            int v = q[1];

            res.push_back( components[u].contains(v) && indices[ u ] < indices[ v ] );
        }

        return res;
    }
};

int main()
{
    std::vector<std::vector<int>> prereqs = {{2,3},{2,1},{0,3},{0,1}};
    std::vector<std::vector<int>> queries = {{0,1},{0,3},{2,3},{3,0},{2,0},{0,2}};
    Solution().checkIfPrerequisite( 4, prereqs, queries );
}
