#include <iostream>
#include <vector>


bool is_valley(int i, std::vector<int>& ratings)
{
    int n = ratings.size();

    if (n <= 1)
    {
        return true;
    }

    if (i == 0)
    {
        return ratings[i] <= ratings[i + 1];
    }

    else if (i == ratings.size() - 1)
    {
        return ratings[i] <= ratings[i - 1];
    }
    else
    {
        return ratings[i] <= ratings[i + 1] && ratings[i] <= ratings[i - 1];
    }

}

class Solution
{
public:
    int candy(std::vector<int>& ratings)
    {
        int n = ratings.size();
        std::vector<int> valleys = {};
        std::vector<int> candies = std::vector<int>(n, 1);
        for (int i = 0; i < n; i++)
        {
            if (is_valley(i, ratings))
            {
                std::cout << "Valley: " << i << '\n';
                valleys.push_back(i);
            }
        }

        for (int valley : valleys)
        {
            // left pass
            for (int i = valley - 1; i >= 0; i--)
            {
                if (ratings[i] > ratings[i + 1])
                {
                    candies[i] = std::max(candies[i], candies[i + 1] + 1);
                }
            }
            // right pass
            for (int i = valley + 1; i < n; i++)
            {
                if (ratings[i] > ratings[i - 1])
                {
                    candies[i] = std::max(candies[i], candies[i - 1] + 1);
                }
            }
        }

        int res = 0;
        for (int c : candies)
        {
            res += c;
        }
        return res;
    }
};

int main()
{
    std::vector<int> nums = std::vector( {1,2,87,87,87,2,1} );
    Solution sol = Solution();
    std::cout << sol.candy(nums) << '\n';
    return 0;
}
