// saurabhraj042
// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
class Solution {
public:
    TreeNode* build(vector<int>& I, vector<int>& P,int ioS,int ioE,int poS,int poE){
        if(poS>poE || ioS>ioE) return NULL;
        
        TreeNode* n = new TreeNode(P[poE]);
        
        int ind = -1;
        for(int i=ioS;i<=ioE;i++){
            if(I[i]==P[poE]){
                ind = i;
                break;
            }
        }
        int len = ind-ioS;
        
        n->left = build(I,P,ioS,ind-1,poS,poS+len-1);
        n->right = build(I,P,ind+1,ioE,poS+len,poE-1);
        
        return n;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1);
    }
};