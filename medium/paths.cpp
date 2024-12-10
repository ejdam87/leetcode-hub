#include <vector>

class Solution
{
public:
    long long uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid)
    {
        std::vector< std::vector<long long> > opt = {};

        for ( int i = 0; i < obstacleGrid.size(); i++ )
        {
            std::vector<long long> row = {};
            for ( int j = 0; j < obstacleGrid[0].size(); j++)
            {
                row.push_back( 0 );
            }

            opt.push_back( row );
        }

        if ( obstacleGrid[ obstacleGrid.size() - 1 ][ obstacleGrid[0].size() - 1 ] == 1 )
        {
            return 0;
        }

        opt[ obstacleGrid.size() - 1 ][ obstacleGrid[0].size() - 1 ] = 1;

        for ( int i = obstacleGrid.size() - 1; i >= 0; i-- )
        {
            for ( int j = obstacleGrid[0].size() - 1; j >= 0; j-- )
            {
                if (i == obstacleGrid.size() - 1 && j == obstacleGrid[0].size() - 1)
                {
                    continue;
                }

                long long a = i + 1 >= obstacleGrid.size() ? 0 : opt[i + 1][j];
                long long b = j + 1 >= obstacleGrid[0].size() ? 0 : opt[i][j + 1];
                opt[i][j] = obstacleGrid[i][j] == 1 ? 0 : a + b;
            }
        }

        return opt[0][0];
    }
};
