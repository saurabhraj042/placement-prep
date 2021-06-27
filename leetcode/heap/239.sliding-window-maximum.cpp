// saurabhraj042
// https://leetcode.com/problems/sliding-window-maximum/
// best explanation https://leetcode.com/problems/sliding-window-maximum/discuss/1054583/Explanationintuition-with-comments-and-code.or-C%2B%2Bor-priority_queue-approach
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        
        vector<int> ans;
        
        auto n = nums.size();
        if (n < 2 || k == 1) {
          return nums;
        }
        
     
        for(int i=0;i<n;i++){
            while(!pq.empty() && pq.top().second<=i-k) pq.pop();
            
            pq.push({nums[i],i});
            
            if(i>=k-1)
                ans.push_back(pq.top().first);
        }
        
        return ans;
    }
};

/*
    Approach:

We try using priority queue, which stores the maximum element at the top of the queue.
Our job is to find the maximum element from all possible windows of given size k, and store it in an answer vector to output it.
Example:
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation:

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
From the above example, we observe few hints to solve and get the output vector.

We make a window of given size k, and put it into out priority queue (pq). The top element of this pq, gives us the maximum of the 1st window.
Now, its observable in the example above, that the next window is obtained by sliding the window by one place.
Now, we need to find the maximum of this window. To get this, we push the immediate next element of the last element of the previous window, into pq.
But now, size of the window is k+1 (k size of prev window and the next element adds 1 more to it).
Hence we need to keep in consideration to check whether the largest element of the pq, is with the range of (i-k) to k.
point no. 4 will become more clear, from the code
.

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& a, int k)
    {
        vector<int> ans;
        int n = a.size();
        priority_queue<pair<int, int>> pq;
        
        for(int i=0;i<n;i++)
        {
            while(!pq.empty() && pq.top().second<=(i-k)) //step no. 4
                pq.pop(); // if the top of the pq( the max element value of the window), is from an element outside of the k-sized window, we pop it
            
            pq.push({a[i], i}); // a priority queue, which stores elements of the array, with its corresponding index number.
            
            if(i >= k-1) // k sized window obtained, so we push the max element of it, into answer vector.
                ans.push_back(pq.top().first); 
        }
        
        return ans;
    }
};
*/