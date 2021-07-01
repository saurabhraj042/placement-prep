// https://leetcode.com/problems/partition-list/
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode left(0),right(0);
        ListNode* l = &left;
        ListNode* r = &right;
        
        while(head){
            if(head->val < x){
                l = l->next = head;
            }else{
                r = r->next = head;
            }
            head = head->next;
        }
        
        r->next = NULL;
        l->next = right.next;
        
        return left.next;
    }
};