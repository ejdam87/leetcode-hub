#include <vector>
#include <algorithm>

int WHITE = 0;
int GRAY = 1;
int BLACK = 2;

class Solution
{
private:
    bool topoSort(std::vector<std::vector<int>>& g, int v, std::vector<int>& colors, std::vector<int>& ordered)
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
    std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>>& prerequisites)
    {
        std::vector<std::vector<int>> g = {};
        std::vector<int> colors = {};
        for (int i = 0; i < numCourses; i++)
        {
            g.push_back({});
            colors.push_back(WHITE);
        }

        for (auto& prereq : prerequisites)
        {
            g[ prereq[1] ].push_back( prereq[0] );
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
                    return {};
                }
            }
        }

        std::reverse(topo.begin(), topo.end());
        return topo;

    }
};
