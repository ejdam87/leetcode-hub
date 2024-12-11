#include <string>
#include <vector>

class Solution
{
public:
    std::string longestPalindrome(std::string s)
    {
        std::vector< std::vector<bool> > palim( s.length(), std::vector<bool>( s.length(), false ) );

        for ( int i = 0; i < s.length(); i++ )
        {
            palim[i][i] = true;
        }

        for ( int i = s.length() - 2; i >= 0; i-- )
        {
            for ( int j = i + 1; j < s.length(); j++ )
            {
                if ( i + 1 > j - 1 )
                {
                    palim[i][j] = s[j] == s[i];
                }
                else
                {
                    palim[i][j] = s[i] == s[j] && palim[i + 1][j - 1];
                }
            }
        }

        int best = 0;
        int best_i = 0;

        for (int i = 0; i < s.length(); i++)
        {
            for (int j = i; j < s.length(); j++)
            {
                if (!palim[i][j])
                {
                    continue;
                }

                int l = j - i + 1;
                if (l > best)
                {
                    best = l;
                    best_i = i;
                }
            }
        }

        return s.substr(best_i, best);
    }
};
