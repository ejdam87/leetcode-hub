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
    ListNode* rotateRight(ListNode* head, int k)
    {
        if (head == nullptr)
        {
            return head;
        }

        std::vector<int> vals = {};
        for (ListNode* it = head; it != nullptr; it = it -> next)
        {
            vals.push_back( it -> val );
        }

        k %= vals.size();
        int i = 0;
        for (ListNode* it = head; it != nullptr; it = it -> next)
        {
            int j = i - k < 0 ? i - k + vals.size() : i - k;
            it -> val = vals[ j ];
            i++;
        }

        return head;
    }
};
