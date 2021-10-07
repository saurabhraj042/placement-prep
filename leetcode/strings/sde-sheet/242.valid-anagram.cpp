// @author: Saurabh Raj
// @user: saurabhraj042
// https://leetcode.com/problems/valid-anagram/description/

class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> mp;

        for(int i=0;i<s.length();i++) mp[ s[i] ]++;

        for(int i=0;i<t.length();i++) mp[ t[i] ]--;

        for(auto x:mp){
            if( x.second!=0 ) return false;
        }

        return true;
    }
};

