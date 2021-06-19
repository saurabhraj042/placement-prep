// saurabhraj042
//https://leetcode.com/problems/kth-smallest-element-in-a-bst/
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
    void trv(TreeNode* a,int &b,int &c){
        if(a){
            trv(a->left,b,c);
            b--;
            if(b==0){
                c = a->val;
                return;
            }
            trv(a->right,b,c);
        }
        return;
    }
    int kthSmallest(TreeNode* A, int B) {
        int c;
        trv(A,B,c);
        return c;
    }   

};