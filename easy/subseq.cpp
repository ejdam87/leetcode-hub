#include <string>
#include <iostream>

class Solution
{
public:
    bool isSubsequence(std::string s, std::string t)
    {
        int m = s.length();
        int n = t.length();

        if (m > n)
        {
            return false;
        }

        std::string refined = {};
        int j = 0;
        for (int i = 0; i < m; i++)
        {
            bool success = false;
            while (j < n)
            {
                if (s[i] == t[j])
                {
                    refined.push_back( t[j] );
                    success = true;
                    j++;
                    break;
                }
                j++;
            }

            if (!success)
            {
                return false;
            }
        }

        std::cout << refined << '\n';

        return refined.find(s) >= 0 ? true : false;
    }
};

int main()
{
    std::cout << Solution().isSubsequence("aaa", "bbaaaa") << '\n';
}
