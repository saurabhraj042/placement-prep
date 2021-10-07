class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> umap;
        int pairs = 0;

        for(auto x : nums){
            pairs += umap[x];
            umap[x]++;
        }
        
        return pairs;
    }
    
//     nums = [1,2,3,1,1,3]
        
//         1 -> 0, 3, 4, 5
//         2 -> 1
//         3 -> 2, 5
        
//         we need to find pairs (i, j) such that
//         nums[i] == nums[j] && i < j
};