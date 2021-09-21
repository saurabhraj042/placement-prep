// @author: Saurabh Raj
// @user: saurabhraj042
// https://leetcode.com/problems/majority-element-ii/description/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // Optimal Approach Moore Voting Algo
        int n =  nums.size();
        if(n==1) return nums;

        vector<int> ans;
        
        int can1,can2,c1=0,c2=0;
        
        for(auto x:nums){

            if( x==can1) c1++;
            else if( x==can2 ) c2++;
            else if( c1==0 ){can1=x;c1++;}
            else if( c2==0 ){can2=x;c2++;}
            else{ c1--;c2--;}
        }

        c1=0,c2=0;
        for( auto x:nums ){
            if(x==can1) c1++;
            else if(x==can2) c2++;
        }

        if(c1>n/3) ans.push_back(can1);
        if(c2>n/3) ans.push_back(can2);
        
        return ans;
    }
};

