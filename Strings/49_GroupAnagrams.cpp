class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> anagrams;
        unordered_map<string, vector<string>> umap;
        
        for(size_t i = 0; i < strs.size(); ++i) {
            string sorted = strs[i];
            sort(sorted.begin(), sorted.end());
            umap[sorted].push_back(strs[i]);
        }
        
        for(auto& i : umap) {
            anagrams.push_back(i.second);
        }
        
        return anagrams;
    }
};