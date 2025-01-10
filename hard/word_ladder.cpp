#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <utility>

class Solution
{
private:
    bool is_succ( std::string& s1, std::string& s2 )
    {
        int d = 0;
        for ( int i = 0; i < s1.length(); i++ )
        {
            if ( s1[i] != s2[i] )
            {
                d++;
            }
            if ( d > 1 )
            {
                return false;
            }
        }
        return d == 1;
    }

public:
    int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string>& wordList)
    {
        wordList.push_back( beginWord );
        std::unordered_map< std::string, std::vector< std::string > > g;

        for ( auto& w1 : wordList )
        {
            for ( auto& w2 : wordList )
            {
                if ( is_succ( w1, w2 ) )
                {
                    g[ w1 ].push_back( w2 );
                }
            }
        }

        std::queue< std::pair< std::string, int > > q;
        std::unordered_set< std::string > visited; 
        q.push( {beginWord, 1} );

        while ( !q.empty() )
        {
            auto [ s, t ] = q.front();
            q.pop();

            if ( s == endWord )
            {
                return t;
            }

            for ( auto& adj : g[ s ] )
            {
                if ( !visited.contains( adj ) )
                {
                    visited.insert( adj );
                    q.push( {adj, t + 1} );
                }
            }
        }

        return 0;
    }
};
