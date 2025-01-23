#include <vector>
#include <set>

class Solution
{
public:
    int countServers(std::vector<std::vector<int>>& grid)
    {
        std::vector< int > row_sums = std::vector<int>( grid.size(), 0 );
        std::vector< int > col_sums = std::vector<int>(grid[0].size(), 0);
        int total = 0;
        for ( int i = 0; i < grid.size(); i++ )
        {
            for ( int j = 0; j < grid[0].size(); j++ )
            {
                row_sums[i] += grid[i][j];
                col_sums[j] += grid[i][j];
                total += grid[i][j];
            }
        }

        for ( int i = 0; i < grid.size(); i++ )
        {
            for ( int j = 0; j < grid[0].size(); j++ )
            {
                if ( grid[i][j] && row_sums[i] == 1 && col_sums[j] == 1 )
                {
                    total--;
                }
            }
        }

        return total;

    }
};
