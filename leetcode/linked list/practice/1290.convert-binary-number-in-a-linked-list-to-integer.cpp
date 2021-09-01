// https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        return soln_2(head);
    }
    
    // Brute Force : Uses extra space and conversion operation
    int soln_1(ListNode* head){
        string binary = "";
        
        while(head){
            binary += to_string(head->val);
            head = head->next;
        }
        
        int ans = stoi(binary, 0, 2);
        
        return ans;
    }
    
    int soln_2(ListNode* head){
        int cur;
        int sum = 0;
        
        while(head){
            cur = head->val;
            head = head->next;
            
            sum *= 2;
            sum += cur;
        }
        
        return sum;
    }
    
    /*
            Using the number 123 as an example, then from basic Math, we know this:

1 is in the hundreds column so it’s value is 100
2 is in the tens column so it’s value is 20
3 is in the ones column so it’s value is just 3
Let’s forget about binary for a second and focus on decimal counting since that’s what humans use. So, if we were to convert the string “123” to integer 123, we’ll go through each character one at a time.

When we start with the first character, 1, we don’t really know it’s value is yet. i.e whether it’s in the millions or hundreds or thousands etc. But, we do know that if we encounter a character again, then it’s value has to go up by x10.

So if we get 1, we assume it’s just 1. Then we encounter 2. At this point, we realize that the previous was is no longer just a 1 but (1 x 10). So we do that arithmetic and then add the current value. This is how is looks like in tabular form.

Loop	Character	Operation	  Result
1	    ‘1’	        1	          1
2	    ‘2’	        (1x10) + 2	  12
3	    ‘3’	        (12*10) + 3	  123
Note: Operation is always the previous multiplied by the counting system. In this this, we're doing decimal so x10. If we were doing hex, it'll x16. Binary will be x 2.

Using this logic, let’s come back to binary. It’s exactly the same except for instead of multiplying by 10 when we encounter the next digit, we multiply by 2. So If we have a LinkeList 1 -> 0 -> 1 and apply the same logic, this is how it'll be

Loop	Character	Operation	  Result
1	    ‘1’	        1	          1
2	    ‘0’	        (1x2) + 0	  2
3	    ‘1’	        (2*2) + 1	  5
    */
};