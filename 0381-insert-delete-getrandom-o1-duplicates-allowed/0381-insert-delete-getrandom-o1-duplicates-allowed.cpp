class RandomizedCollection {
public:
    unordered_map<int,vector<int>> m;
    vector<int> nums;
    RandomizedCollection() {
        
    }
    bool insert(int val) {
        bool flag=false;
        if(m.find(val) == m.end())
            flag=true;
        nums.push_back(val);
        m[val].push_back(nums.size()-1);
        return flag;
    }
    
    bool remove(int val) {
        if(m.find(val) == m.end())
            return false;
        int idx=m[val].back();
        m[val].pop_back();  
        
        if(idx != nums.size()-1){
        int last=nums[nums.size()-1];
        
        int temp=nums[idx];
        nums[idx]=nums[nums.size()-1];
        nums[nums.size()-1]=temp;
        
        m[last].pop_back();
        m[last].push_back(idx);
        sort(m[last].begin(),m[last].end());
        }
        
        if((int)m[val].size() == 0)
            m.erase(val);

        nums.pop_back();
        return true;
    }
    
    int getRandom() {
        return nums[random()%nums.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */