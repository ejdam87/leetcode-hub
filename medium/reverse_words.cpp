#include <string>
#include <vector>
#include <iostream>

class Solution
{
public:
    std::string reverseWords(std::string s)
    {
        std::vector< std::string > words = {};
        bool word = false;
        std::string current = {};

        for (char c : s)
        {
            if (c != ' ')
            {
                word = true;
            }
            else if (word)
            {
                words.push_back(current);
                current.clear();
                word = false;
            }

            if (word)
            {
                current.push_back(c);
            }
        }

        if (word)
        {
            words.push_back(current);
        }
        
        std::string res = {};
        int n = words.size();

        for (int i = n - 1; i >= 0; i--)
        {
            res += words[i];
            if (i != 0)
            {
                res += " ";
            }
        }

        return res;

    }
};

int main()
{
    Solution sol = Solution();
    std::cout << sol.reverseWords("Ahoj cicuska moja mila") << '\n';
}