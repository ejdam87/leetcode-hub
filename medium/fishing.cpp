#include <vector>
#include <queue>
#include <utility>

class Solution
{
private:
    int reachable_fish(
            std::vector<std::vector<int>>& grid,
            std::pair<int, int> start,
            std::vector<std::vector<bool>>& visited
        )
    {
        std::queue< std::pair<int, int> > q;
        q.push( start );
        visited[ start.first ][ start.second ] = true;
        int total = 0;

        while ( !q.empty() )
        {
            auto curr = q.front();
            q.pop();
            total += grid[ curr.first ][ curr.second ];
            std::vector<std::pair<int, int>> neighs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0} };

            for ( auto [dx, dy] : neighs )
            {
                int nx = curr.first + dx;
                int ny = curr.second + dy;

                if ( nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[0].size() || visited[nx][ny] || grid[nx][ny] == 0 )
                {
                    continue;
                }

                visited[nx][ny] = true;
                q.push( {nx, ny} );
            }

        }

        return total;
    }

public:
    int findMaxFish(std::vector<std::vector<int>>& grid)
    {
        std::vector< std::vector<bool> > visited = std::vector( grid.size(), std::vector<bool>( grid[0].size(), false ) );
        int best = 0;

        for ( int i = 0; i < grid.size(); i++ )
        {
            for ( int j = 0; j < grid[0].size(); j++ )
            {
                if ( grid[i][j] != 0 && !visited[i][j] )
                {
                    best = std::max( best, reachable_fish( grid, {i, j}, visited ) );
                }
            }
        }
        return best;
    }
};
