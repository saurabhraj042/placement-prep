// saurabhraj042
//https://leetcode.com/problems/binary-tree-paths/
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        // iterative app
        vector<string> a;
        
        /*
         we need two stacks for this purpose because
         we also have to keep track of the path till
         the for each node at any pt of time
        */
        stack<TreeNode*> s1;
        stack<string> s2;

        s1.push(root);
        s2.push(to_string(root->val));

        while(!s1.empty()){
            TreeNode* c = s1.top();
            string s = s2.top();
            s1.pop();
            s2.pop();

            if(c->left){
                s1.push(c->left);
                s2.push(s + "->" + to_string(c->left->val));
            }

            if(c->right){
                s1.push(c->right);
                s2.push(s + "->" + to_string(c->right->val));
            }

            if(!c->left && !c->right){
                a.push_back(s);
            }
        }

        return a;
    }
};

