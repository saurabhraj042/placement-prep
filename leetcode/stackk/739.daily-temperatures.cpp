// https://leetcode.com/problems/daily-temperatures/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        return soln_2(temp);   
    }
    
    // Using concept of next greater element on left concept
    // O(N) + O(N);
    vector<int> soln_1(vector<int> &a){
        int n = size(a);
        
        stack<int> s;
        s.push(n - 1);
        
        vector<int> res(n);
        
        for (int i = n - 2; i >=0; i--) {
                        
            while (!s.empty() && a[i] >= a[s.top()]) 
                s.pop();
            
            if (!s.empty()) res[i] = s.top() - i;
            
            s.push(i);
        }
        return res;
    }
    
    // Optimal soluchan ^_^
    // O(N) + O(1)
    vector<int> soln_2(vector<int> &a){
        int n = size(a);
        vector<int> res(n,0);
        
        for(int i=n-2;i>=0;i--){
            int j = i+1;
            
            if(a[j] > a[i]){
                res[i] = 1;
                continue;
            }
            
            if(res[j] == 0){
                res[i] = 0;
                continue;
            }
            
            while(j < n && a[i] >= a[j]){
                if(res[j] > 0) j += res[j];
                else{
                    j = n;
                }
            }
            
            if(j < n) res[i] = j - i;
            
        }
        
        return res;
    }
};