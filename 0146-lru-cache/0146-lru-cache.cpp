class LRUCache {
public:
    int n;
    list<int>dll;
    unordered_map<int,pair<list<int>::iterator,int>>mpp;
    LRUCache(int capacity) {
        n=capacity;
    }
    
    int get(int key) {
        if(mpp.find(key)==mpp.end()){
            return -1;
        }
        auto it=mpp[key].first;
        int val=mpp[key].second;
        dll.erase(it);
        dll.push_front(key);
        mpp[key]={dll.begin(),val};
        return val;
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            auto it=mpp[key].first;
            dll.erase(it);
            dll.push_front(key);
            mpp[key]={dll.begin(),value};
        }
        else{
            if(mpp.size()==n){
                int keyto=dll.back();
                dll.pop_back();
                mpp.erase(keyto);
            }
            dll.push_front(key);
            mpp[key]={dll.begin(),value};
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */