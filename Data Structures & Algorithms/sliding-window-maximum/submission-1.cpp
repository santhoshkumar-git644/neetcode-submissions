class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> qu;
        vector<int> result;
        for(int i=0;i<k;i++)
        {
            qu.push({nums[i],i});
        }
        for(int i=0;i<nums.size()-k;i++)
        {
            while(qu.top().second<i)
            {
                qu.pop();
            }
            if(!qu.empty())
            {
                result.push_back(qu.top().first);
            }   
            qu.push({nums[i+k],i+k});
        }
        while(qu.top().second<nums.size()-k)
            {
                qu.pop();
            }
            if(!qu.empty())
            {
                result.push_back(qu.top().first);
            }   
        return result;
    }
};
