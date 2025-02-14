#include <vector>

class ProductOfNumbers
{
    private:
        std::vector<int> nums;

    public:
        ProductOfNumbers(){}

        void add(int num)
        {
            nums.push_back(num);
        }

        int getProduct(int k)
        {
            int res = 1;
            int n = nums.size() - 1;
            for ( int i = 0; i < k; i++)
            {
                res *= nums[n];
                n--;
            }
            return res;
        }
};
