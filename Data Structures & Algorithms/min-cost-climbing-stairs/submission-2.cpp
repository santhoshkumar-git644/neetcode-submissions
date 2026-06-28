class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
       
        if(cost.size()==1)
        {
            return cost[0];
        }
        if(cost.size()==1)
        {
            return min(cost[1],cost[0]);
        }
         cost.push_back(0);
        int min_cost_one_less=0;
        int min_cost_two_less=0;
        int present=INT_MAX;
        for(int i=2;i<cost.size();i++)
        {
            present=min(min_cost_one_less+cost[i-1],min_cost_two_less+cost[i-2]);
            min_cost_two_less=min_cost_one_less;
            min_cost_one_less=present;
        }
        return present;
    }
};
