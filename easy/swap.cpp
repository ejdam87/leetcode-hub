#include <string>
#include <map>

class Solution
{
public:
    bool areAlmostEqual(std::string s1, std::string s2)
    {
        std::map<char, char> want;

        for ( int i = 0; i < s1.length(); i++ )
        {
            for ( int j = 0; j < s2.length(); j++ )
            {
                std::swap( s1[i], s1[j] );
                if ( s1 == s2 )
                {
                    return true;
                }
                std::swap( s1[i], s1[j] );
            }
        }
        return false;
    }
};
