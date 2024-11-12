#include <vector>
#include <iostream>


class Solution
{
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix)
    {
        std::vector<int> res = {};
        int i = 0;
        int j = 0;
        int mi = 0;
        int mj = 0;
        int di = 0;
        int dj = 1;

        int rows = matrix.size();
        int cols = matrix[0].size();
        int k = rows * cols;

        for (int l = 0; l < k; l++)
        {
            res.push_back( matrix[i][j] );
            i += di;
            j += dj;

            if (i == rows - mi)
            {
                di = 0;
                dj = -1;
                i--;
                i += di;
                j += dj;
            }
            if (j == cols - mj)
            {
                di = 1;
                dj = 0;
                j--;
                i += di;
                j += dj;
            }

            if (i == mi - 1)
            {
                di = 0;
                dj = 1;
                i++;
                j += dj;
                mj++;
            }
            if (j == mj - 1)
            {
                di = -1;
                dj = 0;
                j++;
                i += di;
                mi++;
            }
        }

        return res;
    }
};


void printVector(std::vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << ' ' << v[i] << ' ';
    }
    std::cout << '\n';
}


int main()
{
    std::vector< std::vector<int> > matrix = { {1}, {2}, {3} };
    printVector( Solution().spiralOrder(matrix) );
}
