//https://leetcode.com/problems/next-greater-node-in-linked-list/
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        head = reverseList(head);
        stack<int> stk;
        vector<int> ans;
        
        while(head){
            auto val = head->val;
            
            while(!stk.empty() && stk.top() <= val) stk.pop();
            
            int nge = stk.empty() ? 0 : stk.top();
            
            ans.push_back(nge);
            
            stk.push(val);
            
            head = head->next;
        }
        
        reverse(begin(ans), end(ans));
        
        return ans;
    }
    
    
    ListNode* reverseList(ListNode* head){
        ListNode* newHead = nullptr;
        ListNode* next = nullptr;
        
        while(head){
            next = head->next;
            head->next = newHead;
            
            newHead = head;
            head = next;
        }
        
        return newHead;
    }
};