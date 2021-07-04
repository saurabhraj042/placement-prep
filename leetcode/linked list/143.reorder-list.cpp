// https://leetcode.com/problems/reorder-list/
class Solution {
public:
   ListNode* getMid(ListNode* head)
    {
        auto slow = head;
        auto fast = head;
        while(fast->next && fast->next->next)
        {
            slow=slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode* getReverse(ListNode* head)
    {
        auto cur=head;
        ListNode* prev = NULL;
        
        while(cur != NULL)
        {
            ListNode *temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        return prev;
    }
    
    void reorderList(ListNode* head) {
        
        if(!head || !head->next || !head->next->next) return;
        
        ListNode* mid = getMid(head);
        
        ListNode* secondHalf = mid->next;
        mid->next=NULL;
        
        ListNode* revHalf = getReverse(secondHalf);
        
        while(head!=NULL&&revHalf!=NULL)
        {
            ListNode* temp = head->next;
            head->next=revHalf;
            revHalf=revHalf->next;
            head->next->next=temp;
            head = temp;
        }
    } 
};