#include <vector>
#include <unordered_set>
#include <queue>


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

public:
    std::vector<bool> checkIfPrerequisite(
            int numCourses,
            std::vector<std::vector<int>>& prerequisites,
            std::vector<std::vector<int>>& queries
        )
    {
        std::vector<std::vector<int>> g = {};
        std::vector< std::unordered_set<int> > components;
        for (int i = 0; i < numCourses; i++)
        {
            g.push_back({});
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

        std::vector<bool> res;

        for ( auto& q : queries )
        {
            int u = q[0];
            int v = q[1];

            res.push_back( components[u].contains(v) );
        }

        return res;
    }
};
