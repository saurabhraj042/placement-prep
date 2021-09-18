// https://leetcode.com/problems/merge-sorted-array/
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
       soln_2(A,m,B,n);
    }
    
    void soln_1(vector<int>& A, int m, vector<int>& B, int n){
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
    
    // In place merge operation
    void soln_2(vector<int>& A, int m, vector<int>& B, int n){
        int i = m-1;
        int j = n-1;
        int idx = m+n-1;
        
        while(i >= 0 && j >= 0){
            if(A[i] > B[j]){
                A[idx--] = A[i--];
            }else{
                A[idx--] = B[j--];
            }
        }
        
        while(j >= 0){
            A[idx--] = B[j--];
        }
    }
};