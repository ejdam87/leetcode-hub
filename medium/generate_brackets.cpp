#include <vector>
#include <string>
#include <unordered_set>

class Solution {
private:
    void parenthesisRec(int i, int n, std::string current, std::unordered_set<std::string>& res)
    {
        if (i == n)
        {
            res.insert(current);
            return;
        }

        parenthesisRec( i + 1, n, "(" + current + ")", res);
        parenthesisRec( i + 1, n, current + "()", res);
        parenthesisRec( i + 1, n, "()" + current, res);
    }

public:
    std::vector<std::string> generateParenthesis(int n)
    {
        if (n == 1)
        {
            return { "()" };
        }

        std::unordered_set< std::string > unique_res = {};

        for (int i = 1; i <= n / 2; i++)
        {
            auto a = generateParenthesis( i );
            auto b = generateParenthesis( n - i );

            for ( auto& s1 : a )
            {
                for ( auto& s2 : b )
                {
                    if (i == 1)
                    {
                        unique_res.insert( "(" + s2 + ")" );
                    }

                    unique_res.insert( s1 + s2 );
                    unique_res.insert( s2 + s1 );
                }
            }
        }

        std::vector<std::string> res = {};
        for (auto& s : unique_res)
        {
            res.push_back( s );
        }

        return res;
    }
};
