class Solution {
public:
    
    // Finds two endpoints of a palindromic substring
    
    void updateWhileEqual(const string& s, int& curStart, int& curEnd) {
        
        while(curStart >= 0 && curEnd < s.length() && s[curStart] == s[curEnd]) {
                --curStart;
                ++curEnd;
        }
        
        ++curStart;
        --curEnd;
    }
    
    // Updates start and end indices of longest palindromic substring yet if necessary
    
    void updateIfGreater(int& start, int& end, const int& curStart, const int& curEnd) {
        
        if(curEnd - curStart > end - start) {
            start = curStart;
            end = curEnd;
        }
        
    }
    
    
    string longestPalindrome(string s) {
        
        if(s.empty()) {
            return "";
        }
        
        // Start and end of the longest palindromic substring
        
        int start = 0, end = 0;
        
        for(int index = 0; index < s.length(); ++index) {
            
            // Compute longest substring assuming s[index] is the middle of the substring
            
            int curStart = index - 1, curEnd = index + 1;
            
            updateWhileEqual(s, curStart, curEnd);
            
            updateIfGreater(start, end, curStart, curEnd);
            
            // Compute longest substring assuming s[index] & s[index + 1] in the middle of the substring
            
            curStart = index;
            curEnd = index + 1;
            
            updateWhileEqual(s, curStart, curEnd);
            
            updateIfGreater(start, end, curStart, curEnd);
        }
        
        return s.substr(start, end - start + 1);
    }
};