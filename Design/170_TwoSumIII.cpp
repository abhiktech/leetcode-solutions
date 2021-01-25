class TwoSum {
    
private:
    unordered_map<long int, int> nums;
    
public:
    /** Initialize your data structure here. */
    TwoSum() {}
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        ++nums[number];
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        
        for(auto& i : nums) {
            
            if(i.first * 2 == value) {
                
                if(i.second > 1) {
                    return true;
                }
                
            } else if(nums.find(value - i.first) != nums.end()) {
                return true;
            }
            
        }
        
        return false;
    }
};
