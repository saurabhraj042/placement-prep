// saurabhraj042
// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

class Solution {
public:
    Node* connect(Node* A) {
        if(!A) return A;
    
        queue<Node*> q;
        q.push(A);
        
        while(!q.empty()){
            int n = q.size();
            
            for(int i=0;i<n;i++){
                auto c = q.front();
                q.pop();
                
                if(c->left) q.push(c->left);
                if(c->right) q.push(c->right);
                
                if(i==n-1){
                    c->next = NULL;    
                }else{
                    auto nxt = q.front();
                    c->next = nxt;
                }
            }
        }

        return A;
    }
};

