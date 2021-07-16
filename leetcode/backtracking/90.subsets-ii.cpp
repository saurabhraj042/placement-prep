// https://leetcode.com/problems/subsets-ii/
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& a) {
        sort(a.begin(),a.end());
        vector<vector<int>> ans;
        vector<int> temp;
        dfs(a,ans,temp,0);
        return ans;
    }
    
    void dfs(vector<int> &a,vector<vector<int>> &ans,vector<int> &temp,int idx){
        ans.push_back(temp);
        
        for(int i=idx;i<a.size();i++){
            if(i==idx || a[i]!=a[i-1]){
                temp.push_back(a[i]);
                dfs(a,ans,temp,i+1);
                temp.pop_back();
            }
        }
    }
};