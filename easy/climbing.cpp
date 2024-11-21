#include <iostream>

class Solution
{
public:
    int climbStairs(int n)
    {
        int count[n + 2];
        for (int i = 0; i < n + 2; i++)
        {
            count[i] = 0;
        }

        count[0] = 1;
        for (int i = 0; i <= n - 1; i++)
        {
            count[i + 1] += count[i];
            count[i + 2] += count[i];
        }

        return count[n];
    }
};

int main()
{
    std::cout << Solution().climbStairs(6) << '\n';
}
