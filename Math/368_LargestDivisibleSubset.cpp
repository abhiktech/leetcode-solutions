class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        if(nums.empty()) {
            return {};
        }
        
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> dp(nums.size(), vector<int>(2));
        dp[0][0] = 1;
        dp[0][1] = -1;
        
        int max_index = 0;
        
        for(int i = 1; i < nums.size(); ++i) {
            
            int max = 0, k = -1;
            
            for(int j = i - 1; j >= 0; --j) {
                
                if(nums[i] % nums[j] == 0 & dp[j][0] > max) {
                    max = dp[j][0];
                    k = j;
                }
                
            }
            
            dp[i][0] = max + 1;
            dp[i][1] = k;
            
            if(dp[i][0] > dp[max_index][0]) {
                max_index = i;
            }
            
        }

        vector<int> res;
        
        while(max_index != -1) {
           res.push_back(nums[max_index]);
           max_index = dp[max_index][1];
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};