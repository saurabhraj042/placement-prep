// https://leetcode.com/problems/valid-palindrome/
class Solution {
public:
    bool isPalindrome(string s) {
        // Find len of s
        int len = s.length();
        
        // Using two pointer approach
        int left = 0;
        int right = len - 1;
        
        while(left < right){
            // Avoiding those chars which are not alphanumeric
            
            while(left < right && !isalnum(s[left])){
                left++;
            }
            
            while(left < right && !isalnum(s[right])){
                right--;
            }
            
            // whenever char at left != char at right it's not a palindrome
            if(tolower(s[left]) != tolower(s[right])){
                return 0;
            }
            
            left++;
            right--;
        }
        
        return 1;
    }
};