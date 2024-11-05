#include <vector>
#include <algorithm>
#include <iostream>
#include <set>


int binarySearch(const std::vector<int>& arr, int from, int target) {
    int low = from + 1, high = arr.size() - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;  // Avoids overflow
        
        if (arr[mid] == target) {
            return mid;  // Return the index of the element
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;  // Element not found
}

class Solution
{
public:

    std::vector< std::vector<int> > twoSum(std::vector<int>& numbers, int from, int target)
    {
        std::vector< std::vector<int> > res = {};

        for (int i = from; i < numbers.size(); i++)
        {

            int j = binarySearch(numbers, i, target - numbers[i]);
            if (j != -1)
            {
                res.push_back({i, j});
            }
        }

        return res;
    }

    std::vector<std::vector<int>> threeSum(std::vector<int>& nums)
    {

        std::set< std::vector<int> > res = {};

        int c = 0;
        for (int val : nums)
        {
            if (val == 0)
            {
                c++;
            }
        }

        if (c >= 3)
        {
            std::vector< int > new_nums = {};
            for (int val : nums)
            {
                if (val != 0)
                {
                    new_nums.push_back(val);
                }
            }
            new_nums.push_back(0);
            nums = new_nums;
            res.insert({0, 0, 0});
        }
        
        std::sort(nums.begin(), nums.end());

        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            auto two = twoSum(nums, i + 1, -nums[i]);
            for (auto& sample : two)
            {
                std::vector<int> triplet = { nums[i], nums[ sample[0] ], nums[ sample[1] ] };
                res.insert( triplet );
            }
        }

        std::vector< std::vector<int> > real_res = {};
        for (auto v : res)
        {
            real_res.push_back(v);
        }

        return real_res;
    }
};

void printVector(std::vector<int>& v)
{
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << ' ' << v[i] << ' ';
    }
    std::cout << '\n';
}

int main()
{
    std::vector<int> nums = {-2,0,1,1,2};
    auto v = Solution().threeSum(nums);

    for ( auto& vv : v )
    {
        printVector(vv);
    }
}
