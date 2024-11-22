#include <vector>
#include <iostream>
#include <utility>

void printVector(std::vector< std::pair<int, int> > v)
{
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << ' ' << '(' << v[i].first << ' ' << v[i].second << ')' << ' ';
    }
    std::cout << '\n';
}

class Solution
{
public:
    int lengthOfLIS(std::vector<int>& nums)
    {
        std::vector< std::pair<int, int> > opt = std::vector< std::pair<int, int> >(nums.size(), {0, 0});

        for (int i = 0; i < nums.size(); i++)
        {
            int a = 1;
            int last_higher = -1;
            int bj = 0;

            for (int j = 0; j < i; j++)
            {
                if ( nums[j] < nums[i] )
                {
                    if (opt[j].first > opt[bj].first && opt[j].second > last_higher)
                    {
                        bj = j;
                    }
                }
                else
                {
                    last_higher = j;
                    bj = j + 1;
                }
            }

            a = std::max(a, 1 + opt[bj].first);

            int b = i - 1 >= 0 ? opt[i - 1].first : 0;
            if (a > b)
            {
                opt[i] = {a, i};
            }
            else
            {
                opt[i] = {b, opt[i - 1].second};
            }
        }

        printVector(opt);
        return opt.back().first;
    }
};

int main()
{
    std::vector<int> nums = {4,10,4,3,8,9};
    std::cout << Solution().lengthOfLIS(nums) << '\n';
}
