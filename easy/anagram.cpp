#include <string>
#include <unordered_map>

class Solution
{
public:
    bool isAnagram(std::string s, std::string t)
    {
        std::unordered_map<char, int> cs = {};
        std::unordered_map<char, int> ct = {};

        for (char c : s)
        {
            if (cs.find(c) == cs.end())
            {
                cs[c] = 0;
            }
            cs[c]++;
        }

        for (char c : t)
        {
            if (ct.find(c) == ct.end())
            {
                ct[c] = 0;
            }
            ct[c]++;
        }

        for ( auto [k, v] : cs )
        {
            if (ct.find(k) == ct.end())
            {
                return false;
            }

            if ( cs[k] != ct[k] )
            {
                return false;
            }
        }

        for ( auto [k, v] : ct )
        {
            if (cs.find(k) == cs.end())
            {
                return false;
            }

            if ( cs[k] != ct[k] )
            {
                return false;
            }
        }

        return true;

    }
};
