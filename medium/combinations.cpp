#include <vector>

class Solution {
private:
    void combineRec( int i, int n, int k, std::vector<int>& current, std::vector< std::vector<int> >& res )
    {
        if (current.size() == k)
        {
            res.push_back( current );
            return;
        }

        if (i == n + 1)
        {
            return;
        }

        combineRec(i + 1, n, k, current, res);
        current.push_back(i);
        combineRec(i + 1, n, k, current, res);
        current.pop_back();
    }

public:
    std::vector<std::vector<int>> combine(int n, int k)
    {
        std::vector< std::vector<int> > res = {};
        std::vector<int> curr = {};
        combineRec( 1, n, k, curr, res );
        return res;
    }
};
