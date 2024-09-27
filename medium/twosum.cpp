#include <vector>
#include <iostream>

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
    std::vector<int> twoSum(std::vector<int>& numbers, int target)
    {
        for (int i = 0; i < numbers.size(); i++)
        {
            int j = binarySearch(numbers, i, target - numbers[i]);
            if (j != -1)
            {
                return {i + 1, j + 1};
            }
        }
        return {-1, -1};  
    }
};

int main()
{
    std::vector<int> numbers = {1,2,3,4,4,9,56,90};
    std::vector<int> res = Solution().twoSum(numbers, 8);
    std::cout << res[0] << ' ' << res[1] << '\n';
}
