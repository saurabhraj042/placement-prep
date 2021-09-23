class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* s=head;
        ListNode* f=head;
        
        while( f!=NULL && f->next!=NULL){
            s = s->next;
            f = f->next->next;
        }
        
        return s;
    }
};