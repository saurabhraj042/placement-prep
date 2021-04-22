// @author: Saurabh Raj
// @user: saurabhraj042
// https://leetcode.com/problems/implement-strstr/description/

class Solution {
    // KMP algorithm
public:
    int strStr(string haystack, string needle) {
        string temp = needle+'&'+haystack;
        vector<int> pi = prefix_fn(temp);
        
        int ind=-1;
        for(int i=needle.length();i<pi.size();i++){
            if( pi[i]==needle.length() ){
                ind =i;
                break;
            }
        }
        if( ind>-1 ) return ind-pi[ind]-needle.length();

        return -1;
    }

    vector<int> prefix_fn(string s){
        vector<int> pi(s.length());

        for(int i=1;i<s.length();i++){

            int j = pi[i-1];

            while( j>0 && s[i]!=s[j] ) j=pi[j-1];

            if( s[i]==s[j] ) j++;
            
            pi[i] = j;
        }

        return pi;
    }
};

