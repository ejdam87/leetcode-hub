#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>

class line
{
public:
    std::pair< int, int > dir;
    std::vector<int> point;

    line( std::pair<int, int> d, std::vector<int> p ) : dir(d), point(p) {} 
};

class Solution
{
private:
    bool colinear( std::pair<int, int> v, std::pair<int, int> u )
    {
        return v.first * u.second - v.second * u.first == 0;
    }

public:
    int maxPoints(std::vector<std::vector<int>>& points)
    {
        if (points.size() == 1)
        {
            return 1;
        }

        std::vector< line > lines = {};

        int best = 0;
        for ( int i = 0; i < points.size(); i++ )
        {
            for ( int j = i + 1; j < points.size(); j++ )
            {
                std::pair<int, int> dir = { points[i][0] - points[j][0], points[i][1] - points[j][1] };
                lines.push_back( {dir, points[i]} );

                int current = 2;
                for (int k = j + 1; k < points.size(); k++)
                {
                    std::pair<int, int> p2p = { points[k][0] - points[i][0], points[k][1] - points[i][1] };
                    if (colinear(p2p, dir))
                    {
                        current++;
                    }
                }
                best = std::max(best, current);
            }
        }

        return best;
    }
};

int main()
{
    std::vector< std::vector<int> > points = { {-184, -551}, {-105, -467}, {-90, -394}, {-60, -248}, {115, 359}, {138, 429}, {60, 336}, {150, 774}, {207, 639}, {-150, -686}, {-135, -613}, {92, 289}, {23, 79}, {135, 701}, {0, 9}, {-230, -691}, {-115, -341}, {-161, -481}, {230, 709}, {-30, -102} };
    Solution().maxPoints( points );
}
