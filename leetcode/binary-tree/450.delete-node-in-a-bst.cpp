// https://leetcode.com/problems/delete-node-in-a-bst/
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {    
        if(!root) return root;
        
        if(key < root->val){
            root->left = deleteNode(root->left, key);
            return root;
        }
        
        else if(key > root->val){
            root->right = deleteNode(root->right, key);
            return root;
        }
        
        else{
            if(!root->left){
                return root->right;
            } else if(!root->right){
                return root->left;
            } else {
                TreeNode* min = root->right;
                
                while(min->left) min = min->left;
                
                root->val = min->val;
                
                root->right = deleteNode(root->right, min->val);
                return root;
            }
        }
    }
};