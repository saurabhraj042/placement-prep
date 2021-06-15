// saurabhraj042
//https://leetcode.com/problems/remove-element/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = A.size();
        int ind = 0;

        for(int i=0;i<n;i++){
            if( A[i]!=B ){
                A[ind++] = A[i];
            }
        }

        return ind++;
    }
};

