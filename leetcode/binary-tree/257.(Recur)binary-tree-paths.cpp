// saurabhraj042
//https://leetcode.com/problems/binary-tree-paths/
class Solution {
public:
    void trav(TreeNode* n,vector<string> &a,string s){

        // whenever we reach the leaf node we push it in our ans
        if(!n->left && !n->right){
            a.push_back(s);
            return;
        }

        if(n->left) trav(n->left,a,s + "->" + to_string(n->left->val));
        if(n->right) trav(n->right,a,s + "->" + to_string(n->right->val));
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        // Recursive soln
        vector<string> a;
        trav(root,a,to_string(root->val));
        return a;
    }
};

