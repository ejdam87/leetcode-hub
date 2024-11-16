#include <vector>

int WHITE = 0;
int GRAY = 1;
int BLACK = 2;

class Solution
{
private:
    bool hasCycleFrom(int node, std::vector<int>& colors, std::vector<std::vector<int>>& g )
    {

        for (int succ : g[node])
        {
            if (colors[succ] == GRAY)
            {
                return true;
            }
            else if (colors[succ] == WHITE)
            {
                colors[succ] = GRAY;
                if ( hasCycleFrom(succ, colors, g) )
                {
                    return true;
                }
            }
        }

        colors[node] = BLACK;
        return false;
    }

public:
    bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites)
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
            g[ prereq[0] ].push_back( prereq[1] );
       }

       for (int node = 0; node < numCourses; node++)
       {
            if (colors[node] == BLACK)
            {
                continue;
            }
            
            if (hasCycleFrom(node, colors, g))
            {
                return false;
            }
       }

       return true;
    }
};
