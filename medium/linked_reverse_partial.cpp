
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right)
    {
        
        if (left == right)
        {
            return head;
        }

        ListNode* start = head;
        ListNode* prevStart = nullptr;
        for (int i = 1; i < left; i++)
        {
            if (i == left - 1)
            {
                prevStart = start;
            }

            start = start -> next;
        }

        ListNode* realStart = start;

        ListNode* nxt = start -> next;
        start -> next = nullptr;
        ListNode* nxtnxt;
        for (int i = left; i < right; i++)
        {
            nxtnxt = nxt -> next;
            nxt -> next = start;
            start = nxt;
            nxt = nxtnxt;
        }

        if (prevStart != nullptr)
        {
            prevStart -> next = start;
        }

        realStart -> next = nxtnxt;

        if (left == 1)
        {
            return start;
        }
        return head;
    }
};

int main()
{
    ListNode n1 = ListNode(1);

    Solution().reverseBetween(&n1, 1, 1);
}
