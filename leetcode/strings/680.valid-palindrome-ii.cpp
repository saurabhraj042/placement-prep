class Solution {
public:
    bool validPalindrome(string s) {
        return soln_1(s);
    }
    
    bool soln_1(string s){
        int  n = s.length();
        int i = 0;
        int j = n - 1;
        
        while(i < j){
            if(s[i] != s[j]){
                int i1 = i + 1;
                int j1 = j;
                int i2 = i;
                int j2 = j - 1;
                
                while(i1 < j1 && s[i1] == s[j1]){ i1++;j1--;}
                while(i2 < j2 && s[i2] == s[j2]){i2++;j2--;}
                
                return i1 >= j1 or i2 >= j2;
            }
            
            i++;
            j--;
        }
        
        return true;
    }
   
};