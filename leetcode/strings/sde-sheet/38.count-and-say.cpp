// @author: Saurabh Raj
// @user: saurabhraj042
// https://leetcode.com/problems/count-and-say/description/

class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";

        while(--n){
            string temp = "";

            for(int i=0;i<ans.length();){

                int j = i+1;
                int cnt = 1;

                while( j<ans.length() && ans[i]==ans[j] ){
                    j++;
                    cnt++;
                }

                i = j;
                temp += to_string(cnt) + ans[i-1];
            }

            ans = temp;
        }

        return ans;

    }
};

