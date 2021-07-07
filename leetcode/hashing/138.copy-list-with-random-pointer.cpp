// https://leetcode.com/problems/copy-list-with-random-pointer/
class Solution {
public:
    Node* copyRandomList(Node* A) {
        // Brute force approach O(N) aux space for hashmap
        if(!A) return A;
        unordered_map<Node*,Node*> mp;
        auto head = A;

        while(A){
            mp[A] = new Node(A->val);
            A = A->next;
        }

        Node* new_list = mp[head];

        while(head){
            mp[head]->next = mp[head->next];
            mp[head]->random = mp[head->random];
            head = head->next;
        }

        return new_list;
    }
};