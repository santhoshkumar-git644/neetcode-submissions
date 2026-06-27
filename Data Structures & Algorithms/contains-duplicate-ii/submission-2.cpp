class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        if(nums.size()==1)
        {
            return false;
        }
        for(int i=0;i<=k && k<nums.size();i++)
        {
            mp.insert({nums[i],1});
        }
        if(mp.size()!=k+1)
        {
            return true;
        }
        for(int i=0;i<nums.size()-k-1;i++)
        {
            mp.erase(nums[i]);
            mp.insert({nums[i+k+1],1});
            if(mp.size()!=k+1)
            {
                return true;
            }
        }
        return false;
    }
};