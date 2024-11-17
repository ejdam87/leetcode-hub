#include <vector>
#include <iostream>

class Solution
{
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int low = 0;
        int high = m * n;

        while (low < high)
        {
            int mid = (low + high) / 2;
            int row = mid / n;
            int col = mid % n;

            if (matrix[row][col] == target)
            {
                return true;
            }
            else if (matrix[row][col] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }

        return false;
    }
};

int main()
{
    std::vector< std::vector<int> > matrix = { {1, 2, 3}, {4, 5, 6} };
    std::cout << Solution().searchMatrix(matrix, 0) << '\n';
}
