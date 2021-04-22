// @author: Saurabh Raj
// @user: saurabhraj042
//https://www.geeksforgeeks.org/minimum-characters-added-front-make-string-palindrome/

class Solution
{
public:
    int getMinCnt(string s){
        if(s.length()==1) return 0;

        vector<int> pi = prefix_function(s);

        return s.length()-pi[pi.size()-1];
    } 

    vector<int> prefix_function(string s){
        string temp = s+"&";
        reverse(s.begin(),s.end());
        temp +=s;

        vector<int> pi(temp.length());

        for(int i=1;i<temp.length();i++){
            int j = p[i-1];

            while( j>0 && temp[i]!=temp[j]) j = p[j-1];

            if(temp[i]==temp[j]) j++;

            p[i]=j;
        }

        return pi;
    }   
    
};
