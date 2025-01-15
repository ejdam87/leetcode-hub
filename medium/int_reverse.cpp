#include <cstdint>
#include <cmath>

class Solution
{
public:
    int reverse(int x)
    {
        std::int64_t res = 0;
        int sign = x < 0 ? -1 : 1;
        std::int64_t bound = x < 0 ? static_cast<std::int64_t>(INT32_MAX) + 1 : INT32_MAX;
        std::int64_t long_x = static_cast<std::int64_t>(x) * sign;
        while ( long_x > 0 )
        {
            res *= 10;
            res += long_x % 10;
            if (res > bound)
            {
                return 0;
            }

            long_x /= 10;
        }

        return sign * res;
    }
};
