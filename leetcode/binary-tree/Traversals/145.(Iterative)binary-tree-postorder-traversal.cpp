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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> stack;
        vector<int> ans;
        TreeNode* last=NULL;
        
        while(root || !stack.empty()){
            if(root){
                stack.push(root);
                root = root->left;
            }else{
                TreeNode* n = stack.top();
                
                if(n->right && n->right!=last){
                    root = n->right;
                }else{
                    ans.push_back(n->val);
                    last = n;
                    stack.pop();
                }
            }
        }
        
        return ans;
    }
};