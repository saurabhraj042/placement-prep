class Solution {
public:
    bool rotateString(string s, string goal) {
         if(s.empty()  || goal.empty()) {
            return false;
        }
        if(s.length() != goal.length()) {
            return false;
        }
        if(s.length() == 0) {
            return true;
        }
        return soln_1(s,goal);
    }
    
    // O(N * M)
    bool soln_1(string a,string b){
        string temp = a;
        for(char c: a) temp += c;
        
        for(int i=0;i<size(temp);i++){
            if(temp[i] == b[0]){
                int j = 1;
                int k = i + 1;
                while(j < size(b) && k < size(temp) && temp[k] == b[j]){
                    j++;a
                    k++;
                };
                if(j == size(b)) return true;
            }
        }
        
        return false;
    }
};