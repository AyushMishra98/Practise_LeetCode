class MyHashMap {
public:
    vector<list<pair<int,int>>> m;
    int sz;
    MyHashMap() {
        sz=1000;
        m.resize(sz);
    }
    int hash(int key){
        return key%sz;//returning index
    }
    list<pair<int,int>> :: iterator search(int key){
        int i=hash(key);
        auto it=m[i].begin();
        while(it!=m[i].end()){
            if(it->first == key)
                return it;
            it++;
        }
        return it;
    }
    void put(int key, int value) {
        auto itr=search(key);
        int i=hash(key);
        if(itr == m[i].end())
            m[i].push_back({key,value});
        else
            itr->second=value;
    }
    int get(int key) {
        int i=hash(key);
        auto itr=search(key);
        if(itr != m[i].end())
            return itr->second;
        return -1;
    }
    
    void remove(int key) {
        int i=hash(key);
        auto itr=search(key);
        if(itr != m[i].end())
            m[i].erase(itr);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */