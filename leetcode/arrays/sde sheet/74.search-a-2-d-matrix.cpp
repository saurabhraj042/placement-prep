class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if( matrix.size()==0) return false;
        int m = matrix.size();
        int n = matrix[0].size();
        
        int lo = 0;
        int hi = (n*m)-1;
        
        while( hi>=lo ){
            
            int mid = (hi+lo)/2;
            
            int key = matrix[mid/n][mid%n];
            
            if(key==target){
                return true;
            }
            
            if(key > target) hi = mid-1;
            else lo = mid+1;
        
        }
        
        return false;
      
    }
    
   
     
};