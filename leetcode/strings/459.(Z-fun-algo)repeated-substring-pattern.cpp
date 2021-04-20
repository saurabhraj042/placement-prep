// @author: Saurabh Raj
// @user: saurabhraj042
// https://leetcode.com/problems/repeated-substring-pattern/description/
class Solution {
public:
    bool repeatedSubstringPattern(string s) {

        vector<int> z = getZArray(s);

        for(int i=1;i<z.size();i++){

            if( z[i]+i==s.length()&& s.length()%i==0 ){
                return true;
            }
        }
        return false;
    }

    vector<int> getZArray(string s){
        int n = s.length();
        vector<int> z(n);

        for(int i=1,l=0,r=0;i<n;i++){

            if( i<=r ){
                z[i] = min( z[i-l],r-i+1 );
            }

            while( i+z[i]<n && s[ z[i] ]==s[ i+z[i] ] ) ++z[i];

            if( i+z[i]-1>r ){
                l = i;
                r = i+z[i]-1;
            }
        }

        return z;
    }
};

