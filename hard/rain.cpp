#include <iostream>
#include <vector>
#include <algorithm>

int rectify(int x)
{
    return x > 0 ? x : 0;
}

bool is_peak(int i, std::vector<int>& ratings)
{
    int n = ratings.size();

    if (n <= 1)
    {
        return true;
    }

    if (i == 0)
    {
        return ratings[i] >= ratings[i + 1];
    }

    else if (i == ratings.size() - 1)
    {
        return ratings[i] >= ratings[i - 1];
    }
    else
    {
        return ratings[i] >= ratings[i + 1] && ratings[i] >= ratings[i - 1];
    }

}

class Solution
{
public:
    int trap(std::vector<int>& height)
    {
        int total = 0;
        int n = height.size();
        std::vector<int> peaks = {};

        for (int i = 0; i < n; i++)
        {
            if (is_peak(i, height))
            {
                peaks.push_back(i);
            }
        }

        int m = peaks.size();
        int i = 0;
        while (i < m - 1)
        {
            int mx = -1;
            int mx_h = -1;
            int j = i + 1;

            while ( j < m && height[ peaks[j] ] < height[ peaks[i] ] )
            {
                if (height[ peaks[j] ] >= mx_h)
                {
                    mx = j;
                    mx_h = height[ peaks[j] ];
                }
                j++;
            }

            if (j == m)
            {
                j = mx;
            }

            int smaller = std::min( height[ peaks[i] ], height[ peaks[j] ] );
            for (int k = peaks[i] + 1; k < peaks[j]; k++)
            {
                total += rectify(smaller - height[k]);
            }
            i = j;
        }

        return total;
    }
};

int main()
{
    Solution sol = Solution();
    std::vector<int> heights = {5, 3, 7, 7};
    std::cout << sol.trap(heights) << '\n';
}
