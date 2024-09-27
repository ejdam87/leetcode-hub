#include <vector>
#include <iostream>

class Solution
{
public:
    int maxArea(std::vector<int>& height)
    {
        int i = 0;
        int j = height.size() - 1;
        int best = -1;

        while (i < j)
        {
            int area = (j - i) * ( std::min( height[i], height[j] ) );
            if (area > best)
            {
                best = area;
            }
            if ( height[i] <= height[j] )
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return best;
    }
};

int main()
{
    std::vector<int> height = {1,1};
    std::cout << Solution().maxArea(height) << '\n';
}
