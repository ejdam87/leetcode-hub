#include <vector>
#include <iostream>

class Solution {
public:
    int majorityElement(std::vector<int>& nums)
    {
        int votes = 0;
        int n = nums.size();
        int candidate;

        for (int i = 0; i < n; i++)
        {
            if (votes == 0)
            {
                candidate = nums[i];
                votes = 1;
            }
            else
            {
                if (nums[i] == candidate)
                {
                    votes++;
                }
                else
                {
                    votes--;
                }
            }
        }

        return candidate;
    }
};


int main()
{

    Solution sol = Solution();
    std::vector<int> v = std::vector({3, 3, 4});
    std::cout << sol.majorityElement(v) << '\n';
}
