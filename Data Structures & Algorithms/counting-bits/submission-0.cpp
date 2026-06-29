class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result;
        result.push_back(0);
        result.push_back(1);
        if(n==0)
        {
            return {0};
        }
        if(n==1)
        {
            return {0,1};
        }
        int two_power=2;
        int next_power=4;
        for(int i=2;i<=n;i++)
        {
            if(i==next_power)
            {
                two_power=next_power;
                next_power=next_power*2;
                result.push_back(1);
                continue;
            }
            result.push_back(result[i%two_power]+1);
        }
        return result;
    }
};
