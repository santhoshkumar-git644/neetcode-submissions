class Solution {
public:
    int climbStairs(int n) {
        int prev1=1;
        int prev2=2;
        if(n==1)
        {
            return 1;
        }
        if(n==2)
        {
            return 2;
        }
        int present=INT_MAX;
        for(int i=2;i<n;i++)
        {
            present=prev1+prev2;
            prev1=prev2;
            prev2=present;
        }
    return present;
    }
};
