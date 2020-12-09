class Solution {
public:
    
    bool isPalindrome(const string& s, int low, int high) {
        
        while(low < high) {
            
            if(s[low] != s[high]) {
                return false;
            }
            
            ++low;
            --high;
        }
        
        return true;
    }
    
    int minCut(string s) {
        
        if(s.length() <= 1) {
            return 0;
        }
        
        vector<int> min(s.length(), -1);
        
        min[min.size() - 1] = 0;
        
        for(int i = s.length() - 2; i >= 0; --i) {
            
            for(int j = i; j < s.length() - 1; ++j) {
                
                if(isPalindrome(s, i, j)) {
                    
                    if(min[i] == -1 || min[j + 1] + 1 < min[i]) {
                        min[i] = min[j + 1] + 1;
                    }
                }
            }
            
            if(isPalindrome(s, i, s.length() - 1)) {
                min[i] = 0;
            }
        }
        
        return min[0];
    }
};