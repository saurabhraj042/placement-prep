// https://leetcode.com/problems/insertion-sort-list/
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(0);
        ListNode* pre = &dummy;
        dummy.next = head;
        ListNode* cur = head;
        
        while(cur){
            
            if(cur->next!=NULL && cur->val > cur->next->val){
                
                while(pre->next!=NULL && pre->next->val < cur->next->val){
                    pre = pre->next;
                }
                
                auto temp = cur->next;
                cur->next = cur->next->next;
                temp->next = pre->next;
                pre->next = temp;
                pre = &dummy;
            }else{
                cur = cur->next;
            }
            
        }
        
        return dummy.next;
    }
};