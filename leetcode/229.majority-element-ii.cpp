// @author: Saurabh Raj
// @user: saurabhraj042
// https://leetcode.com/problems/majority-element-ii/description/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //Brute force
        int n =  nums.size();
        if(n==1) return nums;
        map<int,int> mp;

        for(auto x:nums) mp[x]++;

        int target = (int) n/3;
        vector<int> ans;

        for(auto x:mp){

            if(x.second>target){
                ans.push_back(x.first);
            }
        }

        return ans;
    }
};

