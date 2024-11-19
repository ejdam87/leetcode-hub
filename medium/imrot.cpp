#include <vector>
#include <iostream>

class Solution
{
public:
    void rotate(std::vector<std::vector<int>>& matrix)
    {
        int n = matrix.size();
        for (int i = 0; i < n / 2; i++)
        {
            for (int j = i; j < n - i - 1; j++)
            {
                int nxt = matrix[j][n - i - 1];
                matrix[j][n - i - 1] = matrix[i][j];
                int nxt2 = matrix[n - i - 1][n - j - 1];
                matrix[n - i - 1][n - j - 1] = nxt;
                nxt = matrix[n - j - 1][i];
                matrix[n - j - 1][i] = nxt2;
                matrix[i][j] = nxt;
            }
        }
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
    std::vector< std::vector<int> > m = { {5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16} };
    Solution().rotate(m);

    for (auto row : m)
    {
        printVector(row);
    }
}
