#include <string>
#include <iostream>


class Solution
{
public:
    int lengthOfLongestSubstring(std::string s)
    {
        int left = 0;
        int right = 0;
        int best = 0;

        std::string pool = {};

        while (right < s.length())
        {
            while (right < s.length() && pool.find(s[right]) == std::string::npos)
            {
                pool.push_back(s[right]);
                right++;
            }

            best = std::max(best, right - left);
            for (int i = 0; i < pool.length(); i++)
            {
                if (pool[i] == s[right])
                {
                    left = left + i + 1;
                    pool = pool.substr(i + 1);
                    break;
                }
            }
        }

        return best;
    }
};

int main()
{
    std::cout << Solution().lengthOfLongestSubstring("abcaaa") << '\n';
}
