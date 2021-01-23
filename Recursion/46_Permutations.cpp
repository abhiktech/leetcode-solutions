class Solution {
public:
    
    void generatePermutations(vector<int>& nums, deque<int>& unused, vector<vector<int>>& all) {
        
        if(unused.empty()) {
            all.push_back(nums);
            return;
        }
        
        for(size_t i = 0; i < unused.size(); ++i) {
            nums.push_back(unused.front());
            unused.pop_front();
            generatePermutations(nums, unused, all);
            unused.push_back(nums.back());
            nums.pop_back();
        }
        
    }
    
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        if(nums.empty()) {
            return {{}};
        }
        
        deque<int> unused;
        
        while(!nums.empty()) {
            unused.push_front(nums.back());
            nums.pop_back();
        }
        
        vector<vector<int>> all;
        
        generatePermutations(nums, unused, all);
        
        return all;
        
    }
};