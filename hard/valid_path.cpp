#include <vector>
#include <queue>
#include <utility>
#include <set>
#include <unordered_map>

class Solution {
public:
    int minCost(std::vector<std::vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        std::unordered_map< int, std::pair<int, int> > shift = { {1, {0, 1}}, {2, {0, -1}}, {3, {1, 0}}, {4, {-1, 0}} };
        
        using T = std::pair< int, std::pair<int, int> >;
        std::priority_queue< T, std::vector<T>, std::greater<T> > q;
        std::set< std::pair<int, int> > visited;
        q.push( { 0, {m - 1, n - 1} } );

        while ( !q.empty() )
        {
            auto [ cost, pos ] = q.top();
            q.pop();

            if ( visited.contains( pos ) )
            {
                continue;
            }

            visited.insert( pos );

            if ( pos.first == 0 && pos.second == 0 )
            {
                return cost;
            }

            for ( int di = -1; di <= 1; di++ )
            {
                for ( int dj = -1; dj <= 1; dj++ )
                {
                    if ( (di == 0 && dj == 0) || (di != 0 && dj != 0) )
                    {
                        continue;
                    }

                    int ni = pos.first + di;
                    int nj = pos.second + dj;

                    if ( ni < 0 || ni >= m || nj < 0 || nj >= n )
                    {
                        continue;
                    }

                    if ( shift[ grid[ ni ][ nj ] ] == std::pair<int, int>(-di, -dj) )
                    {
                        q.push( { cost, {ni, nj} } );
                    }
                    else
                    {
                        q.push( { cost + 1, {ni, nj} } ); 
                    }
                }
            }
        }

        return -1;
    }
};

int main()
{
    std::vector< std::vector< int > > board = {{1,1,3},{3,2,2},{1,1,4}};
    Solution().minCost( board );
}
