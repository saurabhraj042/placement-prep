class Solution {
public:
    vector<int> plusOne(vector<int>& A) {
        int len = A.size();
        
        int idx = len-1;
        
        while(idx >= 0){
            
            if(A[idx] < 9){
                A[idx]++;
                return A;
            }
            
            A[idx--] = 0;
        }
        
        A[0] = 1;
        A.push_back(0);
        
        return A;
    }
};