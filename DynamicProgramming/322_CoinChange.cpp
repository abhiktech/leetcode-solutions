class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        if(amount == 0) {
            return 0;
        }
        
        vector<int> dp(amount + 1);
        
        for(int cur = 1; cur <= amount; ++cur) {
            
            int min = -1;
            
            for(int i = 0; i < coins.size(); ++i) {
                
                if(coins[i] <= cur && dp[cur - coins[i]] != -1 && (min == -1 || dp[cur - coins[i]] + 1 < min)) {
                    min = dp[cur - coins[i]] + 1;
                }
                
            }
            
            dp[cur] = min;
        }
        
        return dp[amount];
    }
};