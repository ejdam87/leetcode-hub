#include <vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle)
    {
        vector<vector<int>> shortest_paths_from = triangle;
        int n = triangle.size();
        for ( int row = n - 1; row >= 0; row-- )
        {
            for ( int col = 0; col < triangle[row].size(); col++ )
            {
                if ( row + 1 < n )
                {
                    int a = shortest_paths_from[row + 1][col];
                    int b = shortest_paths_from[row + 1][col + 1];
                    shortest_paths_from[row][col] += min(a, b);
                }
            }
        }

        return shortest_paths_from[0][0];
    }
};
