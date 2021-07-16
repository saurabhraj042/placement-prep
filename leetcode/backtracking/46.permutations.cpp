// https://leetcode.com/problems/permutations/
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        fun(nums,temp,ans);
        return ans;
    }
    
    void fun(vector<int> &nums,vector<int> &temp,vector<vector<int>> &ans){
        if(temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }
        
        for(int i=0;i<nums.size();i++){
            if(find(temp.begin(),temp.end(),nums[i]) == temp.end()){
                temp.push_back(nums[i]);
                fun(nums,temp,ans);
                temp.pop_back();
            }
        }
    }
    
    /*
        for any index i we can choose either 1,2, or 3;
    */
};