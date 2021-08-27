// saurabhraj042
// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* A) {
        if(!A) return {};
        
        vector<vector<int>> v;
        queue<TreeNode*> q;
        q.push(A);
        
        while(!q.empty()){
            int n = q.size();
            vector<int> tmp;
            
            while(n--){
                auto n = q.front();
                q.pop();
                
                tmp.push_back(n->val);
                
                if(n->left) q.push(n->left);
                if(n->right) q.push(n->right);
            }
            
            v.push_back(tmp);
        }
        
        reverse(v.begin(),v.end());
        return v;
    }
};

