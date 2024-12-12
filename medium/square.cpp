#include <vector>

class Solution
{
public:
    int maximalSquare(std::vector<std::vector<char>>& matrix)
    {
        int side = 0;

        for ( int i = 0; i < matrix.size(); i++ )
        {
            for ( int j = 0; j < matrix[0].size(); j++ )
            {
                if (matrix[i][j] == '1')
                {
                    side = 1;
                    break;
                }
            }
        }

        if (side == 0)
        {
            return 0;
        }
        
        int m = matrix.size();
        int n = matrix[0].size();

        for ( int i = 2; i <= std::min( m, n ); i++ )
        {
            std::vector< std::vector<char> > nxt = {};
            bool found_square = false;
            for ( int j = 0; j < matrix.size() - 1; j++ )
            {
                std::vector<char> row = {};
                for ( int k = 0; k < matrix[0].size() - 1; k++ )
                {
                    if ( matrix[j][k] == '1' && matrix[j][k + 1] == '1' && matrix[j + 1][k] == '1' && matrix[j+ 1][k + 1] == '1' )
                    {
                        row.push_back( '1' );
                        found_square = true;
                    }
                    else
                    {
                        row.push_back( '0' );
                    }
                }
                nxt.push_back( row );
            }

            if (found_square)
            {
                side = i;
                matrix = nxt;
            }
            else
            {
                break;
            }
        }

        return side * side;
    }
};