#include <vector>

class Solution
{
public:
    bool doesValidArrayExist(std::vector<int>& derived)
    {
        if ( derived.size() == 1 )
        {
            return derived[0] == 0;
        }

        for ( int initial = 0; initial <= 1; initial++ )
        {
            int o_prev = initial;
            for ( int i = 1; i < derived.size(); i++ )
            {
                if (derived[i] == 1 && o_prev == 1)
                {
                    o_prev = 0;
                }
                else if (derived[i] == 1 && o_prev == 0)
                {
                    o_prev = 1;
                }
                else if ( derived[i] == 0 && o_prev == 1 )
                {
                    o_prev = 1;
                }
                else
                {
                    o_prev = 0;
                }
            }

            if ( o_prev ^ initial == derived[0] )
            {
                return true;
            }
        }

        return false;
    }
};