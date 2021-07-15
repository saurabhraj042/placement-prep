// https://leetcode.com/problems/merge-sorted-array/
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        // Simply has to design merge function
        
        int i=0,j=0;
        vector<int> aux;
        
        while(i< m && j<n){
            if(A[i] >= B[j]){
                aux.push_back(B[j++]);
            }else{
                aux.push_back(A[i++]);
            }
        }
        
        while(i<m) aux.push_back(A[i++]);
        while(j<n) aux.push_back(B[j++]);;
        
        for(i=0;i<aux.size();i++){
            A[i] = aux[i];
        }
    }
};