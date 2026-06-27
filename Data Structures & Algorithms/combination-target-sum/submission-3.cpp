class Solution {
public:
    vector<vector<int>> result;
    void sumc(vector<int>& nums, int target,vector<int> present,int sum,int start)
    {
        if(sum==target)
        {
            result.push_back(present);
            return;
        }
        if(sum>target)
        {
            return;
        }
        cout<<"hi";
        for(int i=start;i<nums.size();i++)
        {
            vector<int> hi=present;
            hi.push_back(nums[i]);
            sumc(nums,target,hi,sum+nums[i],i);
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> present;
        int sum=0;
        int start=0;
        sumc(nums,target,present,sum,start);
        return result;
    }
};
