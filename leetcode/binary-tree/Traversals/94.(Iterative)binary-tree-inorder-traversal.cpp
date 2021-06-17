// saurabhraj042
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
    // Iterative Inorder Trav
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> stack;
        
        while(!stack.empty() || root){
            if(root){
                stack.push(root);
                if(root->left){
                    root = root->left;
                }else{
                    root = NULL;
                }
            }else{
                TreeNode* p = stack.top();
                ans.push_back(p->val);
                stack.pop();
                if(p->right){
                    root = p->right;
                }else{
                    root = NULL;
                }
            }
        }
        return ans;
    }
};