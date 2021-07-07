// https://leetcode.com/problems/copy-list-with-random-pointer/
class Solution {
public:
    Node* copyRandomList(Node* A) {
        // Optimal approach in O(1) space
        Node* iter = A;
        
        // Step 1 : Injecting new copy nodes in between adjacent nodes
        while(iter){
            Node* front = iter->next;
            
            Node* copy = new Node(iter->val);
            copy->next = front;
            iter->next = copy;
            
            iter = front;
        }
        
        // Step 2 : Making random links of new copy nodes
        iter = A;
        while(iter){
            Node* copy = iter->next;
            Node* front = iter->next->next;
            
            if(iter->random) copy->random = iter->random->next;
            
            iter = front;
        }
        
        Node *pseudoHead = new Node(0);
        Node *copy = pseudoHead;
        
        iter = A;
        while(iter){
            Node* front = iter->next->next;
            
            copy->next =iter->next;
            iter->next = front;
            copy = copy->next;
            iter = front;
        }
        
        return pseudoHead->next;
    }
};