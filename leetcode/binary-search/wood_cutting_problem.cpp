/*

STATEMENT :
    Given an integer array representing height of trees in a row and an integer 'K' i.e the
    minimum amount of wood needed. Find the minimum height of chainsaw to be used to cut the 
    row of Trees to keep the wastage minimum.

SAMPLE CASE :
    a[] = [20, 15, 10, 17]
    K   = 7

    Observations :
    # Let's say that we set height of chainsaw H = 10
      then if we cut the row of trees the resp wood we get from each tree will be as :
        wood = [10, 5, 0, 7] and total wood = 22 which is far more than what we need
      ans it needs to be optimized.

    # And we can say that the smallest value for 'H' can be 1
    # And maximum height can be " MAX(ARRAY[] given) "

    # So the range for the height of chainsaw is now 1 to Max(A[]), which is a monotonically
      increasing range and our answer lies in this range only
    
    Conclusions :

    ## Since the range is monotonic we can try all possible values in that range to find the
    minimum height which gives atleast K wood , or we can apply BINARY SEARCH for that also

DRY RUN :
    a[] = [20, 15, 10, 17]
    K   = 7

    #   Intially,    start = 1   end = 20
        mid = start + (end - start) / 2 = 10

        so,     H = 10
        after cutting,  wood = [10, 5, 0, 7]    total = 22
        so for this range we are getting,    total > K
        
        **For every height value smaller than 'H' we will be atleast getting 22 units of wood
        **so we can check for heights > H to minimise the wastage of wood
        
        thus we reduce our search space by increasing the start to mid + 1;
    
    #   start = 11, end = 20,   H = 31 / 2 = 15
        wood = [5, 0, 0, 2],    total = 7
        now total is equal to K so we have reached to the sweet spot :)

*/

// Function that will return the amount of wood we get for a given height
int totalWood(vector<int> &a, int height){
    int sum = 0;
    for(int x:a){
        sum += (height >= x) ? x - height : 0;
    }
    return sum;
}

int performBS(vector<int> &a,int K){
    int n = size(a);
    int start = 1;
    int end = -1;
    for(auto x:a){
        end = max(end, x);
    }

    int ans = 0;

    while(start <= end){
        int mid = start + (end - start) / 2;
        int sum = totalWood(a, mid);

        if(sum >= K){
            ans = mid;
            start = mid + 1;
        }else{
            end = mid - 1;
        }
    }

    return ans;
}