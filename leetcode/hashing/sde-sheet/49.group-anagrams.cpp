// https://leetcode.com/problems/group-anagrams/
class Solution {
public:
    string sortString(string s){
        int hash_arr[26] = {0};

        for(char c:s){
            hash_arr[c - 'a']++;
        }

        string new_string = "";
        for(int i=0;i<26;i++){
            for(int j=0;j<hash_arr[i];j++){
                new_string += (char)('a' + i);
            }
        }

        return new_string;
    }
    vector<vector<string>> groupAnagrams(vector<string>& A) {
        unordered_map<string,vector<string>> mp;
    
        for(int i=0;i<A.size();i++){
            string s = A[i];
            // sort(s.begin(),s.end()); this line takes O(mlogm) but we can do better
            // This do string sorting in O(m) time
            s = sortString(s);

            mp[s].push_back(A[i]);
        }

        vector<vector<string>> ans;
        for(auto x:mp){
            auto arr = x.second;
            ans.push_back(arr);
        }

        return ans;
    }
};