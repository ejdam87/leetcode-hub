#include <string>
#include <cctype>
#include <iostream>

class Solution
{
public:
    bool isPalindrome(std::string s)
    {
        std::string refined = {};
        for (char c : s)
        {
            if (std::isalnum(c))
            {
                refined.push_back(std::tolower(c));
            }
        }

        int n = refined.length();
        if (n == 0)
        {
            return true;
        }

        for (int i = 0; i <= n / 2; i++)
        {
            if (refined[i] != refined[n - i - 1])
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    std::cout << Solution().isPalindrome("Aahhaa") << '\n';
}
