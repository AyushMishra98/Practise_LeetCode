class RandomizedSet {
public:
    unordered_map<int,int> m;
    vector<int> nums;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(m.find(val) != m.end())
            return false;
        nums.emplace_back(val);
        m[val]=nums.size()-1;//storing idx of val of nums in map
        return true;
    }
    
    bool remove(int val) {
        if(m.find(val) == m.end())
            return false;
        //perform swaping
        int last=nums.back();
        m[last]=m[val];
        nums[m[val]]=last;

        nums.pop_back();
        m.erase(val);

        return true;
    }
    
    int getRandom() {
        return nums[rand()%nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */