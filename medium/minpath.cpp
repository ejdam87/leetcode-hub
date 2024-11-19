#include <vector>
#include <cstdint>
#include <iostream>


class Solution
{
public:
    int minPathSum(std::vector<std::vector<int>>& grid)
    {
        std::vector<std::vector<int>> opt = {};
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; i++)
        {
            std::vector<int> row = {};
            for (int j = 0; j < m; j++)
            {
                row.push_back(0);
            }
            opt.push_back(row);
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int a = i - 1 >= 0 ? opt[i - 1][j] : INT32_MAX;
                int b = j - 1 >= 0 ? opt[i][j - 1] : INT32_MAX;
                if (a == b && a == INT32_MAX)
                {
                    opt[i][j] = grid[i][j];
                }
                else
                {
                    opt[i][j] = grid[i][j] + std::min(a, b);
                }
            }
        }

        return opt[n - 1][m - 1];  
    }
};

int main()
{
    std::vector<std::vector<int>> grid = { {1, 2, 3}, {4, 5, 6} };
    std::cout << Solution().minPathSum(grid) << '\n';
}
