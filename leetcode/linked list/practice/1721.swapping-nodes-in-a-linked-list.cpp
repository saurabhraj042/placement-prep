// https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        return soln_2(head, k);
    }
    
    /*
        * Brute Force approach will involve finding the Length of the list in O(N)
        * Then traversing the list again to swap Kth and (N-K)th node in the list
    */
    
    // Optimal
    ListNode* soln_2(ListNode* head, int k){
        ListNode* slow = head;// points to first node
        ListNode* fast = head;// will point to first node to be swapped
        
        for(int i = 1; i < k; i++) fast = fast->next;
        
        ListNode* firstNode = fast;
        
        // Now if I move both pointers one step at a time the actual
        // distance bw them remains always 'k' so that when fast 
        // points to the last element the slow ptr points to the kth
        // node from the end
        while(fast->next){
            slow = slow->next;
            fast = fast->next;
        }
        
        ListNode* lastNode = slow;
        
        swap(lastNode->val, firstNode->val);
        return head;
    }
};