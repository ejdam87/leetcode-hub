#include <set>
#include <random>
#include <iostream>

class RandomizedSet
{
private:
    std::set<int> data;
public:
    RandomizedSet() : data(std::set<int>()) {}
    
    bool insert(int val)
    {
        auto res = data.insert(val);
        return res.second;
    }

    bool remove(int val)
    {
        if (data.erase(val) == 0)
        {
            return false;
        }
        return true;
    }

    int getRandom()
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(0, data.size() - 1);

        int i = distrib(gen);
        auto it = data.begin();
        std::advance(it, i);

        return *it;
    }
};

int main()
{
    RandomizedSet randomizedSet = RandomizedSet();
    std::cout << randomizedSet.insert(1) << '\n'; // Inserts 1 to the set. Returns true as 1 was inserted successfully.
    std::cout << randomizedSet.remove(2) << '\n'; // Returns false as 2 does not exist in the set.
    std::cout << randomizedSet.insert(2) << '\n'; // Inserts 2 to the set, returns true. Set now contains [1,2].
    std::cout << randomizedSet.getRandom() << '\n'; // getRandom() should return either 1 or 2 randomly.
    std::cout << randomizedSet.remove(1) << '\n'; // Removes 1 from the set, returns true. Set now contains [2].
    std::cout << randomizedSet.insert(2) << '\n'; // 2 was already in the set, so return false.
    std::cout << randomizedSet.getRandom() << '\n'; // Since 2 is the only number in the set, getRandom()
}
