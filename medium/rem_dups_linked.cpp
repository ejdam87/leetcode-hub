
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
    ListNode* deleteDuplicates(ListNode* head)
    {
        ListNode* start = nullptr;

        ListNode* prev = head;
        ListNode* it = start;
        ListNode* nxt = prev;

        while (prev != nullptr)
        {
            nxt = prev -> next;
            if ( nxt == nullptr || nxt -> val != prev -> val )
            {
                if (start == nullptr)
                {
                    start = prev;
                    it = start;
                    prev = prev -> next;
                }
                else
                {
                    it -> next = prev;
                    it = it -> next;
                    prev = prev -> next;
                }
            }
            else
            {
                while ( nxt != nullptr && nxt -> val == prev -> val )
                {
                    nxt = nxt -> next;
                }
                prev = nxt;
            }
        }

        if (it != nullptr)
        {
            it -> next = nullptr;
        }

        return start;
    }
};

int main()
{
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(2);
    n1 -> next = n2;
    n2 -> next = n3;

    Solution().deleteDuplicates(n1);
}
