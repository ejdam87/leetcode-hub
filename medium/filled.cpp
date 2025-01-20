#include <vector>

class Solution
{
public:
    int firstCompleteIndex(std::vector<int>& arr, std::vector<std::vector<int>>& mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        std::vector<int> row_empty = std::vector<int>(m, n);
        std::vector<int> col_empty = std::vector<int>(n, m);

        std::vector<int> row_of = std::vector<int>(m * n, -1);
        std::vector<int> col_of = std::vector<int>(m * n, -1);

        for ( int i = 0; i < m; i++ )
        {
            for ( int j = 0; j < n; j++ )
            {
                row_of[ mat[i][j] - 1 ] = i;
                col_of[ mat[i][j] - 1 ] = j;
            }
        }

        for ( int i = 0; i < arr.size(); i++ )
        {
            int r = row_of[ arr[i] - 1 ];
            int c = col_of[ arr[i] - 1 ];

            row_empty[ r ]--;
            if ( row_empty[r] == 0 )
            {
                return i;
            }

            col_empty[ c ]--;
            if ( col_empty[ c ] == 0 )
            {
                return i;
            }
        }

        return -1;
    }
};