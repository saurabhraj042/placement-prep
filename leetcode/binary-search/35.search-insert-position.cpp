// @author: Saurabh Raj
// @user: saurabhraj042
//https://leetcode.com/problems/search-insert-position/description/
class Solution {
public:
    int searchInsert(vector<int>& a, int x) {
    if( a.size()==1 ){
        if( a[0]>=x ) return 0;
        else if( a[0]<x ) return 1;
    }
    
    int ind=-1;
    int lo=0,hi=a.size()-1;
    
    while(lo<=hi){
        int mid = lo+(hi-lo)/2;
        
        if( a[mid]==x ){
            return mid;
        }else if( a[mid]<x ){
            lo = mid+1;
            ind = mid+1;
        }else{
            hi = mid-1;
        }
    }
    
    if(ind==-1) return 0;
    return ind;
    }
};

