class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if(s[0] == '0') return 0;

        vector<int> dp(n, 0);
        dp[0] = 1;

        for(int i = 1; i < n; i++) {
            // Single digit valid
            if(s[i] != '0') {
                dp[i] += dp[i-1];
            }

            // Two digit valid
            int two = (s[i-1] - '0') * 10 + (s[i] - '0');
            if(two >= 10 && two <= 26) {
                if(i == 1)
                    dp[i] += 1;
                else
                    dp[i] += dp[i-2];
            }
        }

        return dp[n-1];
    }
};