class Solution {
public:
    int maxProfit(vector<int>& prices) {
        bool buy=false;
        bool sell=false;
        int result=0;
        int present=0;
        for(int i=0;i<prices.size();i++)
        {
            if(i+1<prices.size())
            {
                if(buy)
                {
                    if(prices[i+1]>prices[i])
                    {
                        buy=true;
                    }
                    else
                    {
                        result+=prices[i]-present;
                        sell=true;
                        buy=false;
                    }
                }
                else if(sell)
                {
                    if(prices[i+1]<prices[i])
                    {
                        sell=true;
                    }
                    else
                    {
                        present=prices[i];
                        buy=true;
                        sell=false;
                    }
                }
                else
                {
                    if(prices[i+1]>prices[i])
                    {
                        present=prices[i];
                        buy=true;
                    }
                }
            }
            cout<<result<<"\n";
        }
        if(buy)
        {
            if(prices[prices.size()-1]>present)
            {
                result+=prices[prices.size()-1]-present;
                return result;
            }
            else
            {
                return result;
            }
        }
        return result;
    }
};