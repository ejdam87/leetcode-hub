
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
    ListNode* merge(ListNode* list1, ListNode* list2)
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

private:
    int length( ListNode* l )
    {
        int res = 0;
        while (l != nullptr)
        {
            res++;
            l = l -> next;
        }

        return res;
    }

public:
    ListNode* sortList(ListNode* head)
    {
        if (head == nullptr || head -> next == nullptr)
        {
            return head;
        }

        int l = length(head);

        ListNode* fst = head;
        ListNode* tail = head;

        for (int i = 0; i < l / 2 - 1; i++)
        {
            tail = tail -> next;
        }
        
        ListNode* snd = tail -> next;
        tail -> next = nullptr;

        ListNode* sfst = sortList(fst);
        ListNode* ssnd = sortList(snd);
        return merge( sfst, ssnd );
    }
};

int main()
{
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);

    n4 -> next = n1;
    n1 -> next = n2;
    n2 -> next = n3;

    Solution().sortList( n4 );

}
