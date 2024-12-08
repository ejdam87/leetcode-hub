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
private:
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
                    res = list2;
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
                    res = list1;
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

public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists)
    {
        if (lists.size() == 0)
        {
            return nullptr;
        }

        ListNode* res = lists[0];
        for ( int i = 1; i < lists.size(); i++ )
        {
            res = mergeTwoLists( res, lists[i] );
        }

        return res;
    }
};

