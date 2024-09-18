#include <vector>

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n)
    {
        int i1 = m - 1;
        int i2 = n - 1;
        int j = m + n - 1;

        while (j >= 0)
        {
            if ( (i1 >= 0) && (i2 < 0 || nums1[i1] >= nums2[i2]) )
            {
                nums1[j] = nums1[i1];
                i1--;
            }
            else
            {
                nums1[j] = nums2[i2];
                i2--;
            }


            j--;
        }
    }
};
