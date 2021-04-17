// @author: Saurabh Raj
// @user: saurabhraj042
// https://leetcode.com/problems/roman-to-integer/description/

class Solution {
public:
    int romanToInt(string s) {
        map< char,int > mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;

        int len = s.length();
        int ans = 0;

        for(int i=0;i<len;i++){

            if( mp[s[i]]<mp[s[i+1]] && i+1<len ){
                ans -= mp[s[i]];
            }else{
                ans += mp[s[i]];
            }

        }

        return ans;
        
    }
};

