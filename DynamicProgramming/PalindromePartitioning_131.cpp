class Solution {
public:
    
    bool isPalindrome(const string& str, int low, int high) {
        
        while(low < high) {
            if(str[low] != str[high])
                return false;
            ++low;
            --high;
        }
        
        return true;
    }
    
    vector<vector<string>> partition(string s) {
        
        if(s.empty()) {
            return {{}};
        }
        
        vector<vector<vector<string>>> parts(s.length(), vector<vector<string>>(0, vector<string>(0)));
        
        parts[0].push_back({string(1, s[0])});
        
        for(int i = 1; i < s.length(); ++i) {
            
            for(int j = i; j > 0; --j) {
                
                if(isPalindrome(s, j, i)) {
                    
                    string cur = s.substr(j, i - j + 1);
                    
                    for(int k = 0; k < parts[j - 1].size(); ++k) {
                        
                        parts[i].push_back(parts[j - 1][k]);
                        parts[i][parts[i].size() - 1].push_back(cur);
                    }
                    
                }
            }
            
            if(isPalindrome(s, 0, i)) {
                parts[i].push_back({s.substr(0, i + 1)});
            }
            
        }
        
        return parts[parts.size() - 1];
    }
};