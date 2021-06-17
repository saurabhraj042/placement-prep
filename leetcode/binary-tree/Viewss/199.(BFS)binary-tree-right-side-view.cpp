// saurabhraj042
// https://leetcode.com/problems/binary-tree-right-side-view/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        // BFS Approach
        vector<int> ans;
        if(root==NULL) return ans;

        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int level = q.size();
            
            for(int i=0;i<level;i++){
                TreeNode* cn = q.front();//Front is the current node
                q.pop();

                
                if(i==level-1){
                    //Last node in the current level
                    ans.push_back(cn->val);
                }
                
                //Push all the other nodes for the (level+1)th level
                if(cn->left) q.push(cn->left);
                if(cn->right) q.push(cn->right);
            }
        }
        
        return ans;
        
    }
};