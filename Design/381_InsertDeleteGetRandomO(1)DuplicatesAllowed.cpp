class RandomizedCollection {
    
private:
    
    vector<int> values;
    unordered_map<int, unordered_set<int>> umap;
    
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {}
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        
        umap[val].insert(values.size());
        values.push_back(val);
        
        return umap[val].size() == 1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        
        if(umap[val].empty()) {
            return false;
        }
        
        if(values.back() == val) {
            
            values.pop_back();
            umap[val].erase(values.size());
            
        } else {
            
            int remIndex = -1;
            
            for(auto& index : umap[val]) {
                remIndex = index;
                break;
            }
            
            umap[val].erase(remIndex);
            
            values[remIndex] = values.back();
            values.pop_back();
            
            umap[values[remIndex]].erase(values.size());
            umap[values[remIndex]].insert(remIndex);
        }
        
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        
        if(values.empty()) {
            return -1;
        }
        
        return values[rand() % values.size()];
        
    }
};