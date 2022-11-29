class RandomizedSet {
public:
	vector<int> v;
	unordered_map<int,int> m1;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(m1[val]==0){
            m1[val]=1;
            
            v.push_back(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(m1[val]){
            m1.erase(val);
            return true;
        }
        m1.erase(val);
        return false;
    }
    
    int getRandom() {
        unordered_map<int,int> :: iterator i=m1.begin();
        advance(i,rand()%m1.size());
        return i->first;
    }
};


/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */