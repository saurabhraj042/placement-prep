// https://leetcode.com/problems/fizz-buzz/
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans(n);
        
        for(int i=0;i<n;i++){
            int j = i+1;
            if(j%3==0){
                if(j%5==0){
                    ans[i] = "FizzBuzz";
                }else{
                    ans[i] = "Fizz";
                }
            }else if(j%5==0){
                    ans[i] = "Buzz";
            }else{
                ans[i] = to_string(j);
            }
        }
        
        return ans;
    }
};