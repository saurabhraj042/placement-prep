// @author: Saurabh Raj
// @user: saurabhraj042
// https://leetcode.com/problems/longest-common-prefix/description/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0) return "";
        if(strs.size()==1) return strs[0];

        string prefix = "";

        for(int i=0;i<strs[0].length();i++){

            int j=1;
            for(;j<strs.size() && strs[j].length()>i;j++){
                if( strs[j][i]!=strs[0][i] ) return prefix;
            }

            if(j==strs.size()) prefix +=strs[0][i];
        }

        return prefix;
    }
};


