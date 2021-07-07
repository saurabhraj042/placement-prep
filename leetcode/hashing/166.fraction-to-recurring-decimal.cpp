// https://leetcode.com/problems/fraction-to-recurring-decimal/
class Solution {
public:
    string fractionToDecimal(int a, int b) {
         if(a == 0) return "0";
    
        string ans;

        // Very smart way to avoid using 4 if blocks to get he result sign
        // Just created truth table using Xor

        if(a>0 ^ b>0) ans += '-';

        // Avoiding possible overflows like (-2147483648 / -1).

        long long int n = llabs(a), d = llabs(b), r = n%d;

        ans += to_string(n/d);

        if(r==0) return ans;

        // After decimal part exists

        ans += '.';

        // Map to keep track of reminders and their resp pos
        unordered_map<long long int, int> mp;

        while(r != 0){
            if(mp.find(r) != mp.end()){
                ans.insert(mp[r],"("); // insert() shifts all elments to right to make space
                ans += ')';
                break;
            }

            mp[r] = ans.size(); // last element
            r *= 10;
            ans += to_string(r/d);
            r %= d; 
        }


        return ans;
    }
};