class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int first=-1;
        // if(prices.size()==1)
        // {
        //     return 0;
        // }
        vector<int> maximum(prices.size());
        maximum[prices.size()-1]=prices[prices.size()-1];
        for(int i=0;i<prices.size()-1;i++)
        {
            maximum[prices.size()-2-i]=max(maximum[prices.size()-1-i],prices[prices.size()-2-i]);
        }
        int result=0;
        for(int i=0;i<prices.size();i++)
        {
            cout<<maximum[i]<<"\n";
        }
        for(int i=0;i<prices.size();i++)
        {
            result=max(result,maximum[i]-prices[i]);
        }
        return result;
    }
};
