#include <string>
#include <vector>

class Solution
{
public:
    bool isValid(std::string s)
    {
        std::vector<char> stack = {};

        for (char c : s)
        {
            if (c == '(' || c == '[' || c == '{')
            {
                stack.push_back(c);
            }
            else if ( c == ')' )
            {
                if (stack.size() == 0)
                {
                    return false;
                }
                char back = stack.back();
                stack.pop_back();
                if (back != '(')
                {
                    return false;
                }
            }
            else if ( c == ']' )
            {
                if (stack.size() == 0)
                {
                    return false;
                }
                char back = stack.back();
                stack.pop_back();
                if (back != '[')
                {
                    return false;
                }
            }
            else if ( c == '}' )
            {
                if (stack.size() == 0)
                {
                    return false;
                }
                char back = stack.back();
                stack.pop_back();
                if (back != '{')
                {
                    return false;
                }
            }
        }

        return stack.size() == 0;
    }
};
