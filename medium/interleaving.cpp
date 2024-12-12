#include <string>
#include <vector>

class Solution
{
public:
    bool isInterleave(std::string s1, std::string s2, std::string s3)
    {

        if (s1.length() + s2.length() != s3.length())
        {
            return false;
        }

        std::vector< std::vector< bool > > isIt( s1.length() + 1, std::vector<bool>(s2.length() + 1, false) );

        // isIt[i][j] = (isIt[i - 1][j] && s1[i] == s3[i + j]) || ( isIt[i][j - 1] && s2[j] == s3[i + j] )

        isIt[0][0] = true;
        for ( int i = 1; i <= s1.length(); i++ )
        {
            isIt[i][0] = isIt[i - 1][0] && s1[i - 1] == s3[i - 1];
        }

        for ( int j = 1; j <= s2.length(); j++ )
        {
            isIt[0][j] = isIt[0][j - 1] && s2[j - 1] == s3[j - 1];
        }

        for ( int i = 1; i <= s1.length(); i++ )
        {
            for ( int j = 1; j <= s2.length(); j++ )
            {
                isIt[i][j] = (isIt[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || ( isIt[i][j - 1] && s2[j - 1] == s3[i + j - 1] );
            }
        }

        return isIt[ s1.length() ][ s2.length() ];
    }
};
