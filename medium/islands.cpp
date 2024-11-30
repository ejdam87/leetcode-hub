#include <vector>
#include <set>
#include <utility>

class Solution
{
private:
    void exploreComponent(std::vector<std::vector<char>>& grid,
                          int i,
                          int j,
                          std::set<std::pair<int, int>>& visited)
    {
        for (int di = -1; di <= 1; di++)
        {
            for (int dj = -1; dj <= 1; dj++)
            {
                if (di == 0 || dj == 0)
                {
                    int ni = i + di;
                    int nj = j + dj;

                    if (ni < 0 || ni >= grid.size() || nj < 0 || nj >= grid[0].size())
                    {
                        continue;
                    }

                    if ( grid[ni][nj] != '1' )
                    {
                        continue;
                    }

                    if ( visited.find( {ni, nj} ) == visited.end() )
                    {
                        visited.insert( {ni, nj} );
                        exploreComponent( grid, ni, nj, visited );
                    }
                }
            }
        }
    }

public:
    int numIslands(std::vector<std::vector<char>>& grid)
    {
        std::set< std::pair<int, int> > visited = {};

        int res = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if ( grid[i][j] != '1' )
                {
                    continue;
                }

                if ( visited.find( {i, j} ) == visited.end() )
                {
                    res++;
                    visited.insert( {i, j} );
                    exploreComponent( grid, i, j, visited );
                }
            }
        }

        return res;
    }
};
