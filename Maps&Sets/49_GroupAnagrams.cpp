class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<string> sorted;
        
        for(size_t i = 0; i < strs.size(); ++i) {
            string cur = strs[i];
            sort(cur.begin(), cur.end());
            sorted.push_back(cur);
        }
        
        unordered_map<string, vector<string>> groups;
        vector<vector<string>> res;
        
        for(size_t i = 0; i < sorted.size(); ++i) {
            groups[sorted[i]].push_back(strs[i]);
        }
        
        for(auto& i : groups) {
            res.push_back(i.second);
        }
        
        return res;
    }
};