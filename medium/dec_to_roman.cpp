#include <string>
#include <vector>
#include <iostream>
#include <cmath>

int getFirstDigit(int num) {
    num = std::abs(num);

    int digits = static_cast<int>(std::log10(num));

    int firstDigit = num / static_cast<int>(std::pow(10, digits));

    return firstDigit;
}

class Solution
{
private:
    std::vector<int> decimals = {1000, 500, 100, 50, 10, 5, 1};
    std::vector<char> romans = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};

public:
    std::string intToRoman(int num)
    {
        std::string roman = {};
        while (num > 0)
        {
            int fst = getFirstDigit(num);
            if (fst == 4)
            {
                if (num > 100)
                {
                    roman += "CD";
                    num -= 400;
                }
                else if (num > 10)
                {
                    roman += "XL";
                    num -= 40;
                }
                else
                {
                    roman += "IV";
                    num -= 4;
                }
            }
            else if (fst == 9)
            {
                if (num > 100)
                {
                    roman += "CM";
                    num -= 900;
                }
                else if (num > 10)
                {
                    roman += "XC";
                    num -= 90;
                }
                else
                {
                    roman += "IX";
                    num -= 9;
                }
            }
            else
            {
                for (int i = 0; i < decimals.size(); i++)
                {
                    if (num >= decimals[i])
                    {
                        num -= decimals[i];
                        roman += romans[i];
                        break;
                    }
                }
            }
        }
        return roman;
    }
};

int main()
{
    Solution sol = Solution();
    std::cout << sol.intToRoman(3749) << '\n';
}
