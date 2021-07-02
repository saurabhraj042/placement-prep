// https://leetcode.com/problems/remove-duplicates-from-sorted-list/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        auto ans = head;
        while(head){
            
            while(head->next && head->val == head->next->val){
                head->next = head->next->next;
            }
            
            head = head->next;
        }
        return ans;
    }
};