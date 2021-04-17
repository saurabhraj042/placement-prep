// @author: Saurabh Raj
// @user: saurabhraj042
// https://leetcode.com/problems/reverse-words-in-a-string/description/

class Solution
{
public:
    string reverseWords(string &s)
    {
        int sz = s.size();
        int i = 0, j = 0;

        while (i < sz)
        {
            while (i < sz && s[i] == ' ')
                i++;

            if (i < sz && j > 0){
                s[j] = ' ';
                j++;
            }
           
            int start = j;
            while (i < sz && s[i] != ' '){
                s[j] = s[i];
                i++;
                j++;
            }
           
            reverse(s.begin() + start, s.begin() + j);
        }
        s.resize(j);
        reverse(s.begin(), s.end());
        return s;
    }
};
