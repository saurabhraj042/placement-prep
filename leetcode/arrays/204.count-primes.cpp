// https://leetcode.com/problems/count-primes/
class Solution {
public:
    int countPrimes(int n) {
        // N is a +ve integer
        // Using Sieve of Erastosthenes

        int prime_sieve[n+1] = {1};
        prime_sieve[0] = 0;
        prime_sieve[1] = 0;

        for(int i=2;i * i < n;i++){
            
            if(prime_sieve[i]){
                
                for(int j=i*i;j<n;j += i){
                    prime_sieve[j] = 0;
                }
            }
        }

        int count = 0;

        for(int i=1;i<n;i++){
            if(prime_sieve[i])
                count++;
        }

        return count;
    }
};