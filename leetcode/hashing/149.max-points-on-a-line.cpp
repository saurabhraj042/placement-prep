// https://leetcode.com/problems/max-points-on-a-line/
class Solution {
public:
    int gcd(int a,int b){
        while(b){
            a = a%b;
            swap(a,b);
        }
        return a;
    }
    int maxPoints(vector<vector<int>>& p) {
        int ans = 0;
        int n = p.size();
        
        for(int i=0;i<n;i++){
            unordered_map<string,int> mp;
            int dup = 1;
            
            for(int j=i+1;j<n;j++){
                int dx = p[j][0] - p[i][0];
                int dy = p[j][1] - p[i][1];
                int g = gcd(dx,dy);
                
                if(p[j][0]==p[i][0] and p[j][1]==p[i][1]){
                    dup++;
                }else{
                    mp[to_string(dx/g) + '_' + to_string(dy/g)]++;
                }
            }
            
            ans = max(ans,dup);
            
            for(auto x:mp){
                ans = max(ans,x.second + dup);
            }
        }
        
        return ans;
    }
};