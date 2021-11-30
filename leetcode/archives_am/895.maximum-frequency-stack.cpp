// https://leetcode.com/problems/maximum-frequency-stack/
// https://www.youtube.com/watch?v=KVg4Y0sI4Iw
class FreqStack {
private:
    unordered_map <int, int> fq;
    unordered_map <int, stack<int>> fq_stack;
    int max_fq;
public:
    FreqStack() {
        max_fq = 0;
    }
    
    void push(int val) {
        fq[val]++;
        int val_fq = fq[val];
        
        fq_stack[val_fq].push(val);
        
        max_fq = max(max_fq, val_fq);
    }
    
    int pop() {
        int val = fq_stack[max_fq].top();
        fq_stack[max_fq].pop();
        
        fq[val]--;
        
        if(fq_stack[max_fq].empty()){
            max_fq--;
        }
        
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */