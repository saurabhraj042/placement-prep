class MyHashSet {
private:
    bool set[1000001] = {false};
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        
    }
    
    void add(int key) {
        set[key] = true;
    }
    
    void remove(int key) {
        set[key] = false;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return set[key];
    }
};
