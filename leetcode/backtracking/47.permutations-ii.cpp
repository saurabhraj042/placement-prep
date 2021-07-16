// https://leetcode.com/problems/permutations-ii/
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> used(nums.size(),false);
        dfs(nums,temp,ans,used);
        return ans;
    }
    void dfs(vector<int>& nums,vector<int>& temp,vector<vector<int>> &ans,vector<bool> used){
        if(temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }
        
        for(int i=0;i<nums.size();i++){
            if(used[i] || i>0 && nums[i]==nums[i-1] && !used[i-1]) continue;
            
            temp.push_back(nums[i]);
            used[i] = 1;
            dfs(nums,temp,ans,used);
            used[i] = 0;
            temp.pop_back();
        }
    }

    /*
        Consider the case - [1,1,1]
We mark each of them separately [1a,1b,1c]

Consider the 2nd iteration of for loop in first recursion call:
i = 1
nums = [1a, 1b, 1c]
tempList = []
used = [0 , 0, 0]

We are not adding '1b' to the result bcz i>0 && nums[i] == nums[i-1] && !used[i-1] is true and we will move to next iteration of for loop. This ensures that permutation in which '1b' is added before '1a' are not calculated. In fact, any permutations of the form [1b, ...], [1c, ...] are not calculated.

Consider 2nd iteration of for loop in 2nd recursion call:
i = 1
nums = [1a, 1b, 1c]
tempList = [1a]
used = [1 , 0, 0]

Here, i>0 && nums[i] == nums[i-1] && !used[i-1] is false and we will add '1b' to tempList and recurs further. This ensures only 1 permutation - [1a, 1b, 1c] is calculated.

In this way are calculating only 1 permutation of duplicates [1a,1b,1c].
    */
};