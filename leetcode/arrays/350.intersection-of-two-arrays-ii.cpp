// https://leetcode.com/problems/intersection-of-two-arrays-ii/
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp1,mp2;
        
        for(auto x:nums1) mp1[x]++;
        for(auto x:nums2) mp2[x]++;
        
        vector<int> ans;
        
        for(auto x:mp1){
            if(mp2.find(x.first) != mp2.end()){
                int occ = min(mp2[x.first],x.second);
                
                while(occ--) ans.push_back(x.first);
            }
        }
        
        return ans;
    }
    
    /*
        Another appraoch can be like this
        --> sort both the arrays
        --> for every unique* number in first array find that number and its occ
            in the second array using binary search
    */
    
};