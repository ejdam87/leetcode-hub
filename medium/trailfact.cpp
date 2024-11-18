#include <iostream>
#include <cstdint>

class Solution
{
public:
    int trailingZeroes(int n)
    {
        int res = 0;
        std::uint64_t f = 1;
        for (int i = 1; i <= n; i++)
        {

            int j = i;
            while (j % 10 == 0 && j >= 10)
            {
                std::cout << "Before mult " << i << '\n';
                j /= 10;
                res++;
            }

            f *= j;

            std::cout << f << '\n';

            while (f % 10 == 0)
            {
                std::cout << "After mult " << i << '\n';
                res++;
                f /= 10;
            }
        }

        return res;
    }
};

int main()
{
    std::cout << Solution().trailingZeroes(30) << '\n';
}
