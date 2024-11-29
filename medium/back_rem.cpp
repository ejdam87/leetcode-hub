
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
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode* nth = head;
        ListNode* prev_nth = nullptr;
        ListNode* it = head;
        for (int i = 0; i < n - 1; i++)
        {
            it = it -> next;
        }

        while ( it -> next != nullptr )
        {
            it = it -> next;
            prev_nth = nth;
            nth = nth -> next;
        }

        if (prev_nth == nullptr)
        {
            return nth -> next;
        }

        prev_nth -> next = nth -> next;
        nth -> next = nullptr;
        // delete nth;

        return head;
    }
};
