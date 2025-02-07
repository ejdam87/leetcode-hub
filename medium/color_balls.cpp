#include <vector>
#include <set>
#include <unordered_map>
#include <unordered_set>


class Solution
{
public:
    std::vector<int> queryResults(int limit, std::vector<std::vector<int>>& queries)
    {
        std::unordered_map<int, int> color_of;
        std::unordered_map<int, std::set<int>> colors;
        int num_distinct = 0;

        std::vector<int> res;
        for ( auto& query : queries )
        {
            int ball = query[0];
            int color = query[1];

            if ( !color_of.contains(ball) )
            {
                color_of[ball] = color;

                if ( colors[color].size() == 0 )
                {
                    num_distinct++;
                }

                colors[color].insert(ball);
            }
            else if ( color_of[ball] != color )
            {
                int old_color = color_of[ball];
                color_of[ball] = color;

                colors[old_color].erase(ball);
                if ( colors[old_color].size() == 0 )
                {
                    num_distinct--;
                }

                if ( colors[color].size() == 0 )
                {
                    num_distinct++;
                }

                colors[color].insert(ball);
            }

            res.push_back( num_distinct );
        }

        return res;
    }
};
