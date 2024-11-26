
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        if (list1 == nullptr && list2 == nullptr)
        {
            return nullptr;
        }

        ListNode* res;
        ListNode* nxt;
        bool start = true;

        while ( list1 != nullptr || list2 != nullptr )
        {
            if (list1 == nullptr || (list2 != nullptr && list2 -> val <= list1 -> val))
            {
                if (start)
                {
                    res = new ListNode(list2 -> val);
                    nxt = res;
                    start = false;
                    list2 = list2 -> next;
                    continue;
                }
                nxt -> next = list2;
                list2 = list2 -> next;
            }
            else
            {
                if (start)
                {
                    res = new ListNode(list1 -> val);
                    nxt = res;
                    list1 = list1 -> next;
                    start = false;
                    continue;
                }
                nxt -> next = list1;
                list1 = list1 -> next;
            }

            nxt = nxt -> next;
        }
        
        return res;
    }
};