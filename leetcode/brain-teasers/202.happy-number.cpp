// https://leetcode.com/problems/happy-number/

// This is  algo is not taking constant space
class Solution {
public:
    // Naive Approach
    bool isHappy(int n) {
        set<long long int> s;
        
        while(n != 1){
            int sum = 0;
            int cur = n;
            
            while(cur != 0){
                sum += pow(cur%10,2);
                cur /= 10;
            }
            
            if(s.find(sum) != s.end()) return 0;
            
            n = sum;
            s.insert(sum);
        }
        
        return 1;
    }
};