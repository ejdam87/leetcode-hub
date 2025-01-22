#include <vector>
#include <queue>
#include <set>
#include <utility>

class Solution
{
public:
    std::vector<std::vector<int>> highestPeak(std::vector<std::vector<int>>& isWater)
    {
        auto res = isWater;
        std::set< std::pair<int, int> > visited;
        std::queue< std::pair< std::pair<int, int>, int > > q;

        for ( int i = 0; i < isWater.size(); i++ )
        {
            for ( int j = 0; j < isWater[0].size(); j++ )
            {
                if ( isWater[i][j] )
                {
                    visited.insert( {i, j} );
                    q.push( {{i, j}, 0} );
                }
            }
        }

        while ( !q.empty() )
        {
            auto [ pos, h ] = q.front();
            q.pop();

            res[ pos.first ][ pos.second ] = h;

            std::vector< std::pair<int, int> > neighs = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
            for ( auto [di, dj] : neighs )
            {
                int ni = pos.first + di;
                int nj = pos.second + dj;

                if ( ni < 0 || ni >= res.size() || nj < 0 || nj >= res[0].size() )
                {
                    continue;
                }

                if ( visited.contains( {ni, nj} ) )
                {
                    continue;
                }

                visited.insert( {ni, nj} );
                q.push( { {ni, nj}, h + 1 } );
            }
        }

        return res;
    }
};
