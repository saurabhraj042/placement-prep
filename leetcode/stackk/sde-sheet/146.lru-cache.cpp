
class LRUCache {
public:
    class node{
        public:
            int val;
            int key;
            node* next;
            node* prev;
            node(int _key, int _val){
                val = _val;
                key = _key;
        }
    };
    unordered_map<int, node*> mp;
    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);
    int cap;
    
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void deletenode(node* n){
        auto next = n->next;
        auto prev = n->prev;
        
        prev->next = next;
        next->prev = prev;
    }
    
    void addnode(node* n){
        auto next = head->next;
        head->next = n;
        n->next = next;
        n->prev = head;
        next->prev = n;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            auto res = mp[key];
            int val = res->val;
            deletenode(res);
            addnode(res);
            mp.erase(key);
            mp[key] = head->next;
            return val;
        }
        
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            auto n = mp[key];
            mp.erase(key);
            deletenode(n);
        }
        
        if(mp.size() == cap){
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key, value));
        mp[key] = head->next;
    }
};

