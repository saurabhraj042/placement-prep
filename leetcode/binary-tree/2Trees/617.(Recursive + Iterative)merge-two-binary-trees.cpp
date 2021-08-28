// saurabhraj042
// https://leetcode.com/problems/merge-two-binary-trees/

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        // Iterative app
        std::queue<pair<TreeNode*, TreeNode*>> q;
        
        if (t1 == nullptr) {
            return t2;
        } else if (t2 == nullptr) {
            return t1;
        }
        
        q.emplace(t1, t2);
        
        while (!q.empty()) {
            const auto p = q.front();
            q.pop();
            p.first->val += p.second->val;
        
            if (p.first->left == nullptr) {
                p.first->left = p.second->left;
            } else if (p.second->left != nullptr) {
                q.emplace(p.first->left, p.second->left);
            }

            if (p.first->right == nullptr) {
                p.first->right = p.second->right;
            } else if (p.second->right != nullptr) {
                q.emplace(p.first->right, p.second->right);
            }
        }
        
        return t1;
    }

    // Recursive
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if ( t1 && t2 ) {
            TreeNode * root = new TreeNode(t1->val + t2->val);
            root->left = mergeTrees(t1->left, t2->left);
            root->right = mergeTrees(t1->right, t2->right);
            return root;
        } else {
            return t1 ? t1 : t2;
        }
    }
};

