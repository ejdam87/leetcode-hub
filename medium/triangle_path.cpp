#include <vector>
#include <algorithm>
#include <cstdint>

class Solution
{
public:
    int minimumTotal(std::vector<std::vector<int>>& triangle)
    {
        std::vector<std::vector<int>> opt = {};
        for (int i = 0; i < triangle.size(); i++)
        {
            std::vector<int> row = {};
            for (int j = 0; j < triangle[i].size(); j++)
            {
                row.push_back(0);
            }
            opt.push_back(row);
        }

        opt[0][0] = triangle[0][0];
        for (int i = 1; i < opt.size(); i++)
        {
            for (int j = 0; j < opt[i].size(); j++)
            {
                int a = j - 1 < 0 ? INT32_MAX : opt[i - 1][j - 1];
                int b = j >= opt[i - 1].size() ? INT32_MAX : opt[i - 1][j];
                opt[i][j] = triangle[i][j] + std::min( a, b );
            }
        }

        return *std::min_element( opt[ opt.size() - 1 ].begin(), opt[ opt.size() - 1 ].end());
    }
};
