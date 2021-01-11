class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        
        if len(prices) == 0 or len(prices) == 1:
            return 0
        
        dp = list()
        
        for i in range(len(prices)):
            dp.append([0, 0])
            
        if prices[-1] > 0:
            x = prices[-1]
        else:
            x = 0
        
        dp[-1][1] = x
        
        dp.append([0, 0])
        
        i = len(prices) - 2
        
        while i >= 0:
            
            if dp[i + 1][0] > dp[i + 1][1] - prices[i]:
                dp[i][0] = dp[i + 1][0]
            else:
                dp[i][0] = dp[i + 1][1] - prices[i]
            
            if dp[i + 2][0] > 0:
                dp[i][1] = dp[i + 2][0] + prices[i]
            else:
                dp[i][1] = prices[i]
               
            if dp[i + 1][1] > dp[i][1]:
                dp[i][1] = dp[i + 1][1]
            
            i = i - 1
        
        return dp[0][0]