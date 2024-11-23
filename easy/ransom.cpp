#include <string>
#include <unordered_map>
#include <iostream>

class Solution
{
public:
    bool canConstruct(std::string ransomNote, std::string magazine)
    {
        std::unordered_map< char, int > rCounts = {};
        std::unordered_map< char, int > mCounts = {};

        for ( char c : ransomNote )
        {
            if (rCounts.find(c) == rCounts.end())
            {
                rCounts[c] = 0;
            }
            rCounts[c]++;
        }

        for ( char c : magazine )
        {
            if (mCounts.find(c) == mCounts.end())
            {
                mCounts[c] = 0;
            }
            mCounts[c]++;
        }

        for ( auto [symbol, count] : rCounts )
        {
            if ( mCounts.find(symbol) == mCounts.end() )
            {
                return false;
            }

            if (mCounts[symbol] < rCounts[symbol])
            {
                return false;
            }
        }

        return true;

    }
};
