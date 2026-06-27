class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        vector<int> hash(2010);
        priority_queue<pair<int,int>> hp;
        for(int i=0;i<nums.size();i++)
        {
            hash[nums[i]+1000]++;
        }
        for(int i=0;i<2010;i++)
        {
            if(hash[i]!=0)
            {
                hp.push({hash[i],i-1000});
            }
                
        }
        for(int i=0;i<k;i++)
        {
            result.push_back(hp.top().second);
            hp.pop();
        }
        return result;
    }
};
