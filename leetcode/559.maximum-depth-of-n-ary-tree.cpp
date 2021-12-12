// https://leetcode.com/problems/maximum-depth-of-n-ary-tree/
class Solution {
public:
    int maxDepth(Node* root) {
        if(!root) return 0;
        
        int max_depth = 0;
        
        for(auto child_node : root->children){
            int depth = maxDepth(child_node);
            max_depth = max(max_depth, depth);
        }
        
        return 1 + max_depth;
    }
};