// saurabhraj042
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
class Solution {
public:
    TreeNode* build(vector<int>& A, vector<int>& B,int preInd,int ioS,int ioE){
        if(preInd>A.size()-1 || ioS>ioE) return NULL;
        
        TreeNode* root = new TreeNode(A[preInd]);
        
        int ind = -1;
        for(int i=ioS;i<=ioE;i++){
            if(B[i]==A[preInd]){
                ind = i;
                break;
            }
        }
        
        root->left = build(A,B,preInd+1,ioS,ind-1);
        root->right = build(A,B,preInd+ind-ioS+1,ind+1,ioE);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder,inorder,0,0,inorder.size()-1);
    }
};