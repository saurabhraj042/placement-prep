// https://leetcode.com/problems/add-binary/
class Solution {
public:
    string addBinary(string a, string b) {
        int i = size(a) - 1;
        int j = size(b) - 1;
        int carry = 0;
        
        string ret = "";
        
        while (i >= 0 || j >= 0 || carry == 1) {
            
            if (i >= 0) {
                carry += a[i] - '0';
                i--;
            }
            
            if (j >= 0) {
                carry += b[j] - '0';
                j--;
            }
            
            ret = to_string(carry%2) + ret;
            
            carry /= 2;
        }
        
        return ret;
    }
};