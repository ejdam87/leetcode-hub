#include <string>

class Solution
{
    public:
        std::string clearDigits(std::string s)
        {
            std::string stack;
            for ( char c : s )
            {
                if ( isdigit(c) )
                {
                    stack.pop_back();
                }
                else
                {
                    stack.push_back(c);
                }
            }
            return stack;
        }
    };