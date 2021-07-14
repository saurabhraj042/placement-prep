// https://leetcode.com/problems/happy-number/
class Solution {
public:
    int getSum(int n){
        int sum = 0, tmp;
        while (n) {
            tmp = n % 10;
            sum += tmp * tmp;
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
       // Optimal Approach Using Floyd Cycle Detection Algo from Linked Lists
        
        int slow,fast; // slow and fast pointers which are bound to meet if cycle is there
        
        slow = n;
        fast = n;
        do{
            slow = getSum(slow);
            fast = getSum(fast);// moving fast ptr by two steps
            fast = getSum(fast);
        }while(slow != fast);
        
        if(slow == 1) return true;
        return false;
    }
    
    /*
        Surprisingly, we can apply the Floyd Cycle Detection (the one we used in Detect     Linked List Cycle) on this problem: think of what is a cycle in this case:

    from a number A, we can get to another B using the ways given in this case
    from number B, when we doing the transformation, we will eventually get back to B       again ---> this forms a cycle (infinite loop)

    for example:
    1^2 + 1^2 = 2
    2^2 = 4 ------> notice that from here we are starting with 4
    4^2 = 16
    1^2 + 6^2 = 37
    3^2 + 7^2 = 58
    5^2 + 8^2 = 89
    8^2 + 9^2 = 145
    1^2 + 4^2 + 5^2 = 42
    4^2 + 2^2 = 20
    2^2 + 0^2 = 4 -------> notice that we just get back to 4 again

    Using Floyd Cycle Detection algorithm (fast and slow pointer), we will be able to       actually get the value of B. Then the rest of task would be very simple, we simply       check whether this value will be 1 or not.

    You may ask: what if value "1" also appears in the cycle and we are skipping over       it. Well, in that case, the value that slow and fast are equal to will be 1, as         transformation of 1 is still 1, so we still cover this case.
    */
};