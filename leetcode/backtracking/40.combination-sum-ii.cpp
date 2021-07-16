// https://leetcode.com/problems/combination-sum-ii/
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> temp;
        vector<vector<int>> ans;
        helper(candidates,target,temp,ans,0);
        return ans;
    }
    
    void helper(vector<int> &a,int x,vector<int> &temp,vector<vector<int>> &ans,int s){
        if(x==0){
            ans.push_back(temp);
            return;
        }
        
        if(x < 0) return;
        
        for(int i=s;i<a.size();i++){
            if(i>s && a[i]==a[i-1]) continue;
            temp.push_back(a[i]);
            
            helper(a,x - a[i],temp,ans,i+1); // Elements SHould be used only once
            
            temp.pop_back();
        }
    }
};