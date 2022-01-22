class MyHashMap {
public:
    map<int,int> hashmap;
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        hashmap[key] = value;   
    }
    
    int get(int key) {
        return hashmap.find(key) == hashmap.end() ? -1 : hashmap[key];
    }
    
    void remove(int key) {
        hashmap.erase(key);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */