#include <vector>
#include <queue>
#include <utility>
#include <unordered_set>

class Solution
{
private:
    int pos_to_num( int n, int i, int j )
    {
        int num = n * n;
        num -= n * i;
        return i % 2 == 0 ? num - j : num + j;
    }

    std::pair<int, int> num_to_pos( int n, int num )
    {
        int row = ( n - (num - 1) / n ) - 1;
        int d = n % 2 == 0 ? 0 : 1;
        int col = row % 2 == d ? (n - (num - 1) % n) - 1 : (num - 1) % n;
        return {row, col};
    }

public:
    int snakesAndLadders(std::vector<std::vector<int>>& board)
    {
        int n = board.size();
        std::queue< std::pair<int, int> > q;
        q.push( {1, 0} );
        std::unordered_set< int > visited;

        while ( !q.empty() )
        {
            auto [ pos, t ] = q.front();
            q.pop();

            if ( pos == n * n )
            {
                return t;
            }

            for ( int nxt = pos + 1; nxt <= std::min( n * n, pos + 6 ); nxt++ )
            {
                auto [i, j] = num_to_pos( n, nxt );
                int v = board[i][j];
                int succ = v == -1 ? nxt : v;
                if ( !visited.contains( succ ) )
                {
                    visited.insert( succ );
                    q.push( {succ, t + 1} );
                }
            }
        }

        return -1;
    }
};

int main()
{
    std::vector< std::vector<int> > board = {{-1,-1,19,10,-1},{2,-1,-1,6,-1},{-1,17,-1,19,-1},{25,-1,20,-1,-1},{-1,-1,-1,-1,15}};
    Solution().snakesAndLadders( board );
}
