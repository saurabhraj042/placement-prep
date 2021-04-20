// @author: Saurabh Raj
// @user: saurabhraj042
// https://leetcode.com/problems/string-to-integer-atoi/description/
class Solution
{
public:
    int myAtoi(string s)
    {

        int start = 0;
        int ans = 0;
        int min = pow(2, 31) * -1;
        int max = pow(2, 31) - 1;
        
        int cnt_neg = 0;
        int cnt_pos = 0;

        // Ignoring leading white spaces
        while (s[start] == ' ')
        {
            start++;
        }
        
        // Skipping positive or negative signs
        while (s[start] == '-' || s[start] == '+')
        {
            if (s[start] == '-')
            {
                cnt_neg++;
                
            }

            if (s[start] == '+')
            {
                cnt_pos++;
            }

            start++;
        }

        // if both +ve & -ve sign is there
        if( cnt_pos>0 && cnt_neg>0 ) return 0;

        if( cnt_pos>1 || cnt_neg>1 ) return 0;

        // if the string starts with words
        if (!isdigit(s[start]))
            return 0;

        // Mapping the int part from the string 
        string temp = "";
        while (isdigit(s[start]) && start < s.length())
        {
            temp += s[start];
            start++;
        }
        
        // Checking of out of range exception for stoi
        try
        {
            ans = stoi(temp);
        }
        catch (...)
        {
            if (cnt_neg==1)
                return min;
            else
                return max;
        }

        if (cnt_neg==1)
            ans *= -1;

        if (ans < min)
            return min;
        if (ans > max)
            return max;

        return ans;
    }
};
