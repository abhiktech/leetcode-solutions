class Solution {
public:
    
    void findAllPalindromicSubstrings(const string& s, vector<vector<bool>>& isPalindrome) {
        
        for(int i = 0; i < s.length(); ++i) {
            
            // Assuming one center
            
            int low = i, high = i;
            
            while(low >= 0 && high < s.length() && s[low] == s[high]) {
                isPalindrome[low][high] = true;
                --low;
                ++high;
            }
            
            // Assuming two centers
            
            low = i;
            high = i + 1;
            
            while(low >= 0 && high < s.length() && s[low] == s[high]) {
                isPalindrome[low][high] = true;
                --low;
                ++high;
            }
            
        }
        
    }
    
    void findMinCuts(const string& s, vector<int>& numPartitions, vector<vector<bool>>& isPalindrome) {
        
        for(int i = 1; i < s.length(); ++i) {
            
            int min = i;
            
            for(int j = i; j >= 0; --j) {
                
               if(j == 0) {
                   
                   if(isPalindrome[0][i]) {
                       min = 0;
                   }
                   
               } else {
                   
                    if(isPalindrome[j][i] && numPartitions[j - 1] + 1 < min) {
                        min = numPartitions[j - 1] + 1 ;
                    }  
                   
               }
                
            }
            
            numPartitions[i] = min;
            
        }
        
    }
    
    
    int minCut(string s) {
        
        if(s.length() < 2) {
            return 0;
        }
        
        vector<vector<bool>> isPalindrome(s.length(), vector<bool>(s.length(), false));
        
        findAllPalindromicSubstrings(s, isPalindrome);
        
        vector<int> numPartitions(s.length(), 0);
        
        findMinCuts(s, numPartitions, isPalindrome);
        
        return numPartitions.back();
    }
};