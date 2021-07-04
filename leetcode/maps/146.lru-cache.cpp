// https://leetcode.com/problems/lru-cache/
class LRUCache {
private :
    int t,n;
    map<int,pair<int,int> > mp; // key,value,time
    set<pair<int,int> > st; // time,key

public:
    LRUCache(int capacity) {
         t=0; n =capacity;
        mp.clear(); st.clear();
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;
    
        t++;
        int old_time = mp[key].second;
        
        // Erasing old values
        st.erase({old_time,key});
        mp[key].second = t;
        
        // Updated lru seq
        st.insert({t,key});
        
        return mp[key].first;
    }
    
    void put(int key, int value) {
        t++;
        
        // if it's a page hit we just update the lru seq
        if(mp.find(key)!=mp.end()){
            st.erase({mp[key].second,key});
            mp[key] = {value,t};
            st.insert({t,key}); 
            return;
        }
        
        // Cache full
        if(mp.size()==n){
            auto it = st.begin();
            mp.erase((*it).second);
            st.erase(it);
        }   
        
        // Updating new values
        mp[key] = {value,t};
        st.insert({t,key});
    }
};

