#include <string>
#include <iostream>

class Solution
{
public:
    std::string convert(std::string s, int numRows)
    {
        std::string res = {};
        int n = s.length();

        if (numRows == 1)
        {
            return s;
        }

        for (int i = 0; i < numRows; i++)
        {
            int j = i;
            int down = (numRows - 1) - i;
            int up = i;
            int d = down;
            while (j < n)
            {
                if (d != 0)
                {
                    res.push_back( s[j] );
                }

                j += 2 * d;
                d = d == down ? up : down;
            }
        }

        return res;
    }
};

int main()
{
    Solution sol = Solution();
    std::cout << sol.convert("PAY", 4) << '\n';
}
