// https://leetcode.com/problems/partition-array-into-three-parts-with-equal-sum/
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& a) {
         int sum = accumulate(a.begin(), a.end(), 0);
    
        if(sum%3!=0) return false;

        int subSum = sum/3;

        bool firstFound=false, secondFound = false, thirdFound = false;

        int prefixSum=0;
        for(auto ele : a)
        {
            prefixSum += ele;
            if(!firstFound && prefixSum==subSum) firstFound = true;
            else if(firstFound && !secondFound && prefixSum==subSum*2) secondFound = true;
            else if(firstFound && secondFound && prefixSum==subSum*3) thirdFound = true;
        }

        return (firstFound && secondFound && thirdFound);
    }
    
    
    // Better than Naive app => O(N*N) worst case TC
    bool soln_1(vector<int> &a){
        int t_sum = 0;
        int n = size(a);
        vector<int> pref(n);
        
        for(int i = 0; i < n; i++){
            t_sum += a[i];
            pref[i] = t_sum;
            //cout << pref[i] << " ";
        }
        
        bool ans = false;
        int part = t_sum / 3;
        
        for(int i = 0; i < n; i++){
            if(pref[i] == part){
                for(int j = i + 1; j < n - 1; j++){
                    if(pref[j] - pref[i] == part){
                        ans = true;
                        break;
                    }
                }
            }
        }
        
        return ans;
    }
    
    // Optimal app
    bool soln_2(vector<int> &a){
        int t_sum = 0;
        int n = size(a);
        vector<int> pref(n);
        
        for(int i = 0; i < n; i++){
            t_sum += a[i];
            pref[i] = t_sum;
            //cout << pref[i] << " ";
        }
        
        if(t_sum % 3) return false;
        
        bool ans = false;
        int part = t_sum / 3;
        
        for(int i = 0; i < n; i++){
            if(pref[i] == part){
                int targ = 2 * part;
                int lo = i + 1;
                int hi = n - 2;
                
                while(lo <= hi){
                    int mid = lo + (hi - lo) / 2;
                    
                    if(pref[mid] == targ){
                        ans = true;
                        break;
                    } else if(pref[mid] > targ){
                        hi = mid - 1;
                    } else {
                        lo = mid + 1;
                    }
                }
            }
        }
        
        return ans;
    }
    
    /*
        Intuition

    Suppose the array was indeed breakable into 3 parts with equal sum. Then the array would look like S S S, where S represents the sum
    of each segment of the array. Hence, the entire sum would be S+S+S=3S.
    Assume that the array is breakable into such segments. Let us compute the prefix sum of the array. Since the array resembles S S S,
    therefore the prefix sum would resemble S 2S 3S.
    So we just need to check if the prefix sum contains S 2S & 3S (in the same order). Since the sum is already 3S, we do not need to
    worry about 3S. All that remains is to check whether the prefix sum contains S and 2S such that 2S is to the right of S.
    [Update ---- We do have to check for 3S.]
    */
};