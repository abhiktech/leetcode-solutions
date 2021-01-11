class Solution {
public:
    
    int computeLongest(const string& s, int index) {
        
        int len = 0, cur_len = 0;
        
        stack<bool> cur;
        
        while(index >= 0) {
            
            if(s[index] == ')') {
                cur.push(true);
            } else if(cur.empty()) {
                return len;
            } else {
                cur.pop();
                cur_len += 2;
                
                if(cur.empty()) {
                    len += cur_len;
                    cur_len = 0;
                }
            }
            
            --index;
        }
        
        return len;
    }
    
    
    int longestValidParentheses(string s) {
        
        if(s.empty()) {
            return 0;
        }
        
        vector<int> dp(s.length());
        
        for(int i = 1; i < s.length(); ++i) {

            int cur_longest = computeLongest(s, i);
            dp[i] = (dp[i - 1] > cur_longest) ? dp[i - 1] : cur_longest;
            
        }
        
        return dp[dp.size() - 1];
    }
};