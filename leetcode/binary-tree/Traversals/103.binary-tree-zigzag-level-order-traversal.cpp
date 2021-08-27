// saurabhraj042
// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> v;
        if(!root) return v;
        deque<TreeNode*> q;
        q.push_back(root);
        int l=1;

        while(!q.empty()){
            int n = q.size();
            vector<int> tmp;

            while(n--){
                if(l%2==0){
                    auto p = q.back();
                    q.pop_back();
                    tmp.push_back(p->val);

                    if(p->right) q.push_front(p->right);
                    if(p->left) q.push_front(p->left);
                }
                if(l%2==1){
                    auto p = q.front();
                    q.pop_front();
                    tmp.push_back(p->val);

                    if(p->left) q.push_back(p->left);
                    if(p->right) q.push_back(p->right);
                }
            }

            l++;
            v.push_back(tmp);
        }

        return v;
    }
};

