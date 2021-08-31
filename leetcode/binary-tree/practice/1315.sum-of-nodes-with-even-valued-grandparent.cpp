// https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/
class Solution {
private:
    int sum;
public:
    int sumEvenGrandparent(TreeNode* root) {
        return soln_1(root, nullptr, nullptr);
    }
    
    // Optimal Soluchan bois *_*
    int soln_1(TreeNode* current, TreeNode* parent, TreeNode* grandParent){
        if(!current) return 0;
        int sum = 0;
        
        if(grandParent && grandParent->val%2==0){
            sum += current->val;
        }
        
        sum += soln_1(current->left, current, parent);
        sum += soln_1(current->right, current, parent);
        
        return sum;
    }
    
    
    // My tatti brute force ^_^
    void preOrder(TreeNode* root){
        if(!root) return;
        
        if(root->val%2 == 0){
            check(root);
        }
        
        preOrder(root->left);
        preOrder(root->right);
    }
    
    void check(TreeNode* root){
        if(root->left){
            auto left = root->left;
            if(left->left){
                sum += findSum(left->left);
            }
            if(left->right){
                sum += findSum(left->right);
            }
        }
        
         if(root->right){
            auto right = root->right;
            if(right->left){
                sum += findSum(right->left);
            }
            if(right->right){
                sum += findSum(right->right);
            }
        }
    }
    
    int findSum(TreeNode* root){
        if(!root) return 0;
        return root->val;
    }
};