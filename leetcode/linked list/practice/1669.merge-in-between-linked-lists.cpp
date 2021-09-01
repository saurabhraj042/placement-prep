// https://leetcode.com/problems/merge-in-between-linked-lists/
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        return soln_1(list1, a, b, list2);
    }
    
    ListNode* soln_1(ListNode* x, int a, int b, ListNode* y) {
        ListNode *f = x, *s = x;
        
        for(int i=0;i<a-1;i++) f = f->next;
        
        for(int i=0;i<b;i++) s = s->next;
        
        f->next=y;
        
        while(y->next) y = y->next;
        
        y->next = s->next;
        
        return x;
    }
};