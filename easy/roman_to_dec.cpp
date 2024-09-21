#include <string>
#include <map>
#include <iostream>

class Solution
{
private:
    std::map<char, int> translation = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

public:
    int romanToInt(std::string s)
    {
        int val = 0;
        int i = 0;
        while (i < s.length())
        {
            if (i == s.length() - 1)
            {
                val += translation[s[i]];
                break;
            }

            if (s[i] == 'I' && (s[i + 1] == 'V' || s[i + 1] == 'X'))
            {
                val += translation[s[i + 1]] - 1;
                i += 2;
            }
            else if (s[i] == 'X' && (s[i + 1] == 'L' || s[i + 1] == 'C'))
            {
                val += translation[s[i + 1]] - 10;
                i += 2;
            }
            else if (s[i] == 'C' && (s[i + 1] == 'D' || s[i + 1] == 'M'))
            {
                val += translation[s[i + 1]] - 100;
                i += 2;
            }
            else
            {
                val += translation[s[i]];
                i += 1;
            }
        }

        return val;
    }
};

int main()
{
    Solution sol = Solution();
    std::cout << sol.romanToInt(std::string("MCMXCIV")) << '\n';
}
