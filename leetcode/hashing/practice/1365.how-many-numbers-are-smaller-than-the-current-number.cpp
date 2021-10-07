class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        unordered_map<int,int> mp;
        vector<int> ans;
        vector<int> copy;
        for(auto x : nums) copy.push_back(x);
        
        sort(begin(copy), end(copy));
        
        for(int i=0; i<size(copy); i++){
            if(mp.find(copy[i]) == mp.end()){
                mp[copy[i]] = i;
            }
        }
        
        for(auto x : nums){
            ans.push_back(mp[x]);
        }
        
        return ans;
        
    }
    
//     nums = [8,1,2,2,3]
//             1,2,2,3,8
//             0,1,1,3,4
        
//         1 -> 0
//         2 -> 1
//         3 -> 3
//         8 -> 4
        
//         ans = [4,0,1,1,3]
};