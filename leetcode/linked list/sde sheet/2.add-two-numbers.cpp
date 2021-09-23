// https://leetcode.com/problems/add-two-numbers/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto ans = l2;
        if(!l1) return l2;
        if(!l2) return l1;
        
        int r = 0;
        ListNode* tail;
        
        while(l1 && l2){
            int no = l1->val + l2->val + r;
            l2->val = (no%10);
            
            r = no/10;
            
            l1 = l1->next;
            if(l2->next==nullptr) tail=l2;
            l2 = l2->next;
        }
        
        if(l1) tail->next = l1;
        while(l1){
            int no = l1->val + r;      
            l1->val = no%10;
            r = no/10;
            
            if(l1->next==nullptr) tail=l1;
            l1 = l1->next;
        }
        
        while(l2){
            int no = l2->val + r;      
            l2->val = no%10;
            r = no/10;
            if(l2->next==nullptr) tail=l2;
            l2 = l2->next;
        }
        
        if(r!=0){
            tail->next = (new ListNode(1));
        }
        return ans;
    }
};