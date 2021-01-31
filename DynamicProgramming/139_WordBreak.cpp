class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        if(s.empty()) {
            return false;
        }
         
        unordered_set<string> words;
        
        vector<bool> dp(s.length() + 1, false);
        
        dp.back() = true;
        
        for(int i = 0; i < wordDict.size(); ++i) {
            words.insert(wordDict[i]);
        }
        
        for(int i = s.length() - 1; i >= 0; --i) {
            
            string cur = "";
            
            for(int j = i; j < s.length(); ++j) {
                
                cur += s[j];
                
                if(dp[j + 1] && words.find(cur) != words.end()) {
                    dp[i] = true;
                    break;
                }
                
            }
            
        }
        
        return dp[0];
    }
};
