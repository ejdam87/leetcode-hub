#include <vector>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode* partition(ListNode* head, int x)
    {
        std::vector<int> left = {};
        std::vector<int> right = {};
        for ( ListNode* it = head; it != nullptr; it = it -> next )
        {
            if (it -> val < x)
            {
                left.push_back( it -> val );
            }
            else
            {
                right.push_back( it -> val );
            }
        }

        int i = 0;
        for ( ListNode* it = head; it != nullptr; it = it -> next )
        {
            int v = i < left.size() ? left[i] : right[ i - left.size() ];
            it -> val = v;
            i++;
        }

        return head;
    }
};