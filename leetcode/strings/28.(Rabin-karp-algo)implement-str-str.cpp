// @author: Saurabh Raj
// @user: saurabhraj042
//https://leetcode.com/problems/implement-strstr/description/
class Solution
{
public:
    int strStr(string haystack, string needle)
    {   
        //Rabin Karp method

        int nsize = needle.size();
        int hsize = haystack.size();

        if (nsize == 0)
            return 0;
        if (nsize > hsize)
            return -1;

        int msbPower = 1;
        const int mod = 10000007;

        int nhash = 0;
        int hhash = 0;

        for (int i = 0; i < nsize; i++)
        {
            if (i != 0)
            {
                msbPower *= 26;
                msbPower %= mod;
            }
            nhash = nhash * 26 + needle[i];
            nhash %= mod;

            hhash = hhash * 26 + haystack[i];
            hhash %= mod;
        }

        if (nhash == hhash && !haystack.compare(0, nsize, needle))
            return 0;

       
       
        for (int i = 1; i <= hsize - nsize; i++)
        {
            hhash -= haystack[i - 1] * msbPower;
            hhash %= mod;
            
            if (hhash < 0)
                hhash += mod;
            
            hhash = hhash * 26 + haystack[i + nsize - 1];
            hhash %= mod;
            
            if (nhash == hhash && !haystack.compare(i, nsize, needle))
                return i;
        }
        return -1;
    }
};
