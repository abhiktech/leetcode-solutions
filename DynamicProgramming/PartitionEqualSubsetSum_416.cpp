class Solution {
public:
    bool canPartition(vector<int>& nums) {
    
        int sum = 0;
        
        for(size_t i = 0; i < nums.size(); ++i) {
            sum += nums[i];
        }
        
        // If the sum is odd, then it cannot be divided into equal subsets
        
        if(sum % 2 != 0)
            return false;
        
        sum /= 2;
        
        vector<vector<int>> dp(nums.size() + 1, vector<int>(sum, 0));
        
        /*
           The idea is that assuming our current index is the start of our array
           and we have compued all of the possible sums between 1 and sum / 2 assuming
           the next index is the starting point, we can compute all possible sums
           where our current index is the starting index and see if any sum is equal
           to sum / 2;
        */
        
        for(int i = dp.size() - 2; i >= 0; --i) {
            
            if(nums[i] > sum)
                continue;
            
            if(nums[i] == sum || dp[i + 1][sum - nums[i]] == 1)
                return true;
            
            dp[i][nums[i]] = 1;
            
            for(int j = 1; j < sum; ++j) {
                
                if(dp[i + 1][j] == 1) {
                    dp[i][j] = 1;
                    
                    if(nums[i] + j < sum) {
                        dp[i][nums[i] + j] = 1;
                    }
                }
            }
            
        }
        
        return false;
    }
};