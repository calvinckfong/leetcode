// 380. Insert Delete GetRandom O(1)
class RandomizedSet {
public:
    unordered_map<int, int> data;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (data[val] == 0)
        {
            data[val]++;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if (data.find(val) != data.end())
        {
            data.erase(val);
            return true;
        }
        return false;        
    }
    
    int getRandom() {
        int idx = rand()%data.size();
        auto it = data.begin();
        while (idx) {++it; --idx;}
        return it->first;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
