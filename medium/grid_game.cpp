#include <vector>
#include <algorithm>
#include <utility>

class Solution
{

public:
    long long gridGame(std::vector<std::vector<int>>& grid)
    {
       int n = grid[0].size();
        std::vector<long long> fst_back = { grid[0][n-1] };
        std::vector<long long> snd = { grid[1][0] };

        for ( int i = 1; i < n; i++ )
        {
            snd.push_back( snd.back() + grid[1][i] );
        }

        for ( int i = n - 2; i >= 0 ; i-- )
        {
            fst_back.push_back( fst_back.back() + grid[0][i] );
        }
        std::reverse( fst_back.begin(), fst_back.end() );
        fst_back.push_back( 0 );

        long long res = -1;
        for ( int i = 0; i < n; i++ )
        {
            long long a = i - 1 >= 0 ? snd[ i - 1 ] : 0;
            long long b = i + 1 < n ? fst_back[ i + 1 ] : 0;

            if ( res == -1 || std::max( a, b ) < res )
            {
                res = std::max( a, b );
            }
        }

        return res;
    }
};

int main()
{
    std::vector<std::vector<int>> grid = {{3, 3, 1},{8, 5, 2}};
    int res = Solution().gridGame( grid );
}
