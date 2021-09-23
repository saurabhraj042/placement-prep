class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* s=dummy;
        ListNode* f=dummy;
        
        for(int i=1;i<=n;i++) f = f->next;
        
        while( f->next!=NULL ){
            s=s->next;
            f=f->next;
        }
        
        s->next= s->next->next;
        
        return dummy->next;
        
    }
};