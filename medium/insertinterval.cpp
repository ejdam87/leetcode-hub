#include <vector>
#include <algorithm>

class Solution {
private:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals)
    {
        std::sort(intervals.begin(), intervals.end(), []( std::vector<int> a, std::vector<int> b)
            {
                if (a[0] == b[0])
                {
                    return a[1] < b[1];
                }
                return a[0] < b[0];
            }
        );

        std::vector<std::vector<int>> res = {};

        int fst = 0;
        int lst = 0;

        while (fst < intervals.size() && lst < intervals.size())
        {
            int heighest = intervals[lst][1];
            while ( lst + 1 < intervals.size() && heighest >= intervals[lst + 1][0] )
            {
                lst++;
                heighest = std::max(heighest, intervals[lst][1]);
            }

            res.push_back( {intervals[fst][0], heighest} );
            fst = lst + 1;
            lst = lst + 1;
        }

        return res;
    }

public:
    std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval)
    {
        intervals.push_back( newInterval );
        return merge(intervals);
    }
};