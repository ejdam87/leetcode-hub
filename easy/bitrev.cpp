#include <cstdint>

class Solution {
public:
    std::uint32_t reverseBits(std::uint32_t n)
    {
        std::uint32_t res = 0;
        for (int i = 0; i < 32; i++)
        {
            int j = 32 - i - 1;
            if (i < 16)
            {
                res |= (n & (1 << i)) << (j - i);
            }
            else
            {
                res |= (n & (1 << i)) >> (i - j);
            }
            
        }
        return res;
    }
};