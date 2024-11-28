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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        int carry = (l1 -> val + l2 -> val) / 10;
        ListNode* res = new ListNode((l1 -> val + l2 -> val) % 10);
        ListNode* nxt = res;
        l1 = l1 -> next;
        l2 = l2 -> next;
        while (l1 != nullptr || l2 != nullptr)
        {
            if (l1 == nullptr)
            {
                nxt -> next = new ListNode( (l2 -> val + carry) % 10 );
                carry = (l2 -> val + carry) / 10;
                nxt = nxt -> next;
                l2 = l2 -> next;
            }
            else if (l2 == nullptr)
            {
                nxt -> next = new ListNode( (l1 -> val + carry) % 10 );
                carry = (l1 -> val + carry) / 10;
                nxt = nxt -> next;
                l1 = l1 -> next;
            }
            else
            {
                int sum = (l1 -> val) + (l2 -> val) + carry;
                carry = sum / 10;
                nxt -> next = new ListNode( sum % 10 );
                nxt = nxt -> next;
                l1 = l1 -> next;
                l2 = l2 -> next;
            }
        }

        if (carry == 1)
        {
            nxt -> next = new ListNode(1);
        }
        return res;
    }
};