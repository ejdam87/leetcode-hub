struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
 };
 
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == nullptr)
        {
            return false;
        }

        ListNode* rabbit = head;
        ListNode* turtle = head;

        do
        {
            if (turtle -> next == nullptr)
            {
                return false;
            }
            turtle = turtle -> next;

            for (int i = 0; i < 2; i++)
            {
                if (rabbit -> next == nullptr)
                {
                    return false;
                }
                rabbit = rabbit -> next;
            }
        }
        while (rabbit != turtle);

        return true;

    }
};