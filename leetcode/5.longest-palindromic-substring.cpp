// @author: Saurabh Raj
// @user: saurabhraj042
// https://leetcode.com/problems/longest-palindromic-substring/description/

class Solution
{
public:
    string longestPalindrome(string &s)
    {
        int len = s.length();
        if (len == 1)
            return s;
        int start = 0;
        int mx = 1;

        for (int i = 0; i < len;)
        {
            int left = i - 1;
            int right = i + 1;

            //skip the duplicates both on right 

            while (right < len && s[right] == s[i])
            {
                right++;
            }

            i = right;

            // check for the palindrome *Exanpding*

            while (left >= 0 && right < len && s[left] == s[right])
            {
                left--;
                right++;
            }

            // checking for the length of palindrome if found
            right--;left++;
            int newLen = right - left + 1;

            if (newLen > mx)
            {
                start = left;
                mx = newLen;
            }
        }

        return s.substr(start, mx);
    }
};
