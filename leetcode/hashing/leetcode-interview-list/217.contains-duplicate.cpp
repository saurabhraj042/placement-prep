// https://leetcode.com/problems/contains-duplicate/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> umap;
        for(auto x:nums){
            umap[x]++;
            if(umap[x]>1) return true;
        }
        return false;
    }
};