// https://leetcode.com/problems/subsets/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // Bit Manipulation approach
        
        vector<vector<int>> ans;
        int counter = 0;// Basically it represents index of elements in nums
        int n = nums.size();
        int total_sets = 1<<n;
        
        while(counter < total_sets){
            // Checking for set bits
            vector<int> temp;
            for(int i=0;i<n;i++){
                
                if(counter & (1<<i)){
                    temp.push_back(nums[i]);
                }
            }
            
            ans.push_back(temp);
            counter++;
        }
        
        return ans;
    }
};