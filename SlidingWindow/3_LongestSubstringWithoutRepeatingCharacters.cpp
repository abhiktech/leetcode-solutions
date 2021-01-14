class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        if(s.length() < 2) {
            return s.length();
        }
        
        unordered_map<char, int> occurence;
        
        int low = 0, high = 0, maxLen = 0;
        
        while(high < s.length()) {
            if(occurence.find(s[high]) != occurence.end() && occurence[s[high]] >= low) {
                maxLen = max(maxLen, high - low);
                low = occurence[s[high]] + 1;
            }
            occurence[s[high]] = high;
            ++high;
        }
        maxLen = max(maxLen, high - low);
        
        return maxLen;
    }
};