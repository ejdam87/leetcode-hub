#include <unordered_map>
#include <set>

class NumberContainers
{
    private:
        std::unordered_map<int, int> i_to_n;
        std::unordered_map<int, std::set<int>> n_to_is;
    public:
        NumberContainers(){}

        void change(int index, int number)
        {
            if ( i_to_n.contains( index ) )
            {
                int old = i_to_n[index];
                n_to_is[old].erase(index);
            }
            i_to_n[index] = number;
            n_to_is[number].insert(index);
        }

        int find(int number)
        {
            return n_to_is[number].size() > 0 ? *n_to_is[number].begin() : -1;
        }
};
