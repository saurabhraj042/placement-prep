// https://leetcode.com/problems/target-sum/
class Solution {
public:
    // Reason of using map instead of a table is the given range for target which is -ve also
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        map<pair<int,int>,int> mp;        
        
        return DFS(nums,0,0,target,mp);
    }
    int DFS(vector<int>& nums,int currSum, int i,int target,map<pair<int,int>,int> &cache)
    {
        auto find = cache.find({i,currSum});
        
        if (find != cache.end())
            return find->second;
        
        if (i == nums.size() && currSum == target)
        {
            return 1;
        }
        if(i >= nums.size())
            return 0;

        return cache[{i,currSum}] = DFS(nums,currSum + nums[i],i + 1,target,cache) + DFS(nums,currSum - nums[i],i + 1,target,cache);
    }
};