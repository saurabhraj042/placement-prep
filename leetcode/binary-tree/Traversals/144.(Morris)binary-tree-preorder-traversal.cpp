// saurabhraj042
//https://leetcode.com/problems/binary-tree-preorder-traversal/description/
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
// Morris Algorithm
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* c = root;

        while( c!=NULL ){
            
            if( c->left==NULL ){
                ans.push_back( c->val ) ;
                c = c->right;
            }else{
                TreeNode* p = c->left;
                while( p->right!=NULL && p->right!=c ) p = p->right;

                if( p->right==NULL ){
                    ans.push_back( c->val );
                    p->right = c;
                    c = c->left;
                }else{
                    p->right = NULL;
                    c = c->right;
                }
            }
           
        }

        return ans;
    }
};

