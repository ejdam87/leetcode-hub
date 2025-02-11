#include <string>

class Solution
{
    public:
        std::string removeOccurrences(std::string s, std::string part)
        {
            int k = part.length();
            int j = 0;
            while ((j = s.find(part)) != std::string::npos)
            {
                s.erase(j, k);
            }
    
            return s;
        }
};
