class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,INT_MAX);
        if(amount==0)
        {
            return 0;
        }
        for(int i=0;i<coins.size();i++)
        {
            if(coins[i]>amount)
            {
                continue;
            }
            dp[coins[i]]=1;
        }
        for(int i=1;i<=amount;i++)
        {
            for(int j=0;j<coins.size();j++)
            {
                int num=i-coins[j];
                if(num>0 && dp[num]!=INT_MAX)
                {
                    dp[i]=min(dp[i],dp[num]+1);
                }
            }
        }
        if(dp[amount]==INT_MAX)
        {
            return -1;
        }
        return dp[amount];
    }
};
