#include <string>
#include <iostream>
#include <vector>

class Solution
{
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs)
    {
        int n = strs.size();
        std::size_t min_length = 201; // assumes max possible length is 200
        for (std::string& s : strs)
        {
            min_length = std::min(min_length, s.length());
        }

        std::string res = {};
        for (int i = 0; i < min_length; i++)
        {
            char c = strs[0][i];
            bool success = true;
            for (int j = 0; j < n; j++)
            {
                if (strs[j][i] != c)
                {
                    success = false;
                    break;
                }
            }

            if (success)
            {
                res.push_back(c);
            }
            else
            {
                break;
            }
        }

        return res;
    }
};

int main()
{
    Solution sol = Solution();
    std::vector< std::string > words = { "ahoj", "aho", "ahdrej" };
    std::cout << sol.longestCommonPrefix(words) << '\n';
}
