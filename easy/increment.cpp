#include <vector>

class Solution
{
public:
    std::vector<int> plusOne(std::vector<int>& digits)
    {
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            if (digits[i] + carry == 10)
            {
                digits[i] = 0;
                carry = 1;
            }
            else
            {
                digits[i]++;
                carry = 0;
                break;
            }
        }

        if (carry == 1)
        {
            digits.insert( digits.begin(), 1 );
        }
        return digits;
    }
};
