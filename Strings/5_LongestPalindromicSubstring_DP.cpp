class Solution {
public:
    
    // Updates the endpoints of longest palindromic substring yet if current palindromic substring is longer
    
    void swapIfGreater(int& start, int& end, const int& curStart, const int& curEnd) {
        
        if(curEnd - curStart > end - start) {
            start = curStart;
            end = curEnd;
        }
        
    }
    
    string longestPalindrome(string s) {
        
        if(s.empty()) {
            return "";
        }
        
        // Endpoints of longest palidromic substring
        int start = 0, end = 0;
        
        /*
        - Table that we use to cache our results in our bottom-up dp approach.
        - if dp[i][j] == true, this means that the substring starting from i &
          ending at j is palindromic
        
        */
        vector<vector<bool>> dp(s.length(), vector<bool>(s.length(), false));
        
        // Base case, a single character is always palindromic
        dp[0][0] = true;
        
        for(int i = 1; i < s.length(); ++i) {
            
            // A single character is always palindromic
            dp[i][i] = true;
            
            // Checking if the previous character is equal to current character
            if(s[i - 1] == s[i]) {
                dp[i - 1][i] = true;
                swapIfGreater(start, end, i - 1, i);
            }
            
            /*
            - Upto this point we have calcuated all of the possible palindromic substrings where 
                | The starting points are < i
                | The ending points are < i & >= corresponding starting point of course.
                
            - We want to calculate all possible palindromic substrings where i is the endpoint.
              To do this we have an index j which loops from i - 2 to 0
              At any point, if s[j] == s[i] && dp[j + 1][i - 1] is true, then a palindromic substring also
              occurs where j is the starting point and i is the ending point. So dp[j][i] should be set 
              to true.
            */
            
            for(int j = i - 2; j >= 0; --j) {
                
                if(s[j] == s[i] && dp[j + 1][i - 1]) {
                    dp[j][i] = true;
                    swapIfGreater(start, end, j, i);
                }
                   
            }
    
        }
        
        return s.substr(start, end - start + 1);
    }
};