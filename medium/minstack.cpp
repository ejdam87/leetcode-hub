#include <vector>
#include <algorithm>


class MinStack
{
private:
    std::vector<int> data;

public:
    MinStack()
    {
        data = {};
    }
    
    void push(int val)
    {
        data.push_back(val);
    }
    
    void pop()
    {
        data.pop_back();
    }
    
    int top()
    {
        return data[ data.size() - 1 ];
    }
    
    int getMin()
    {
        return *std::min_element(data.begin(), data.end());
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
