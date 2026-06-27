class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>> result;
        for(int i=0;i<nums.size();i++)
        {
            int left=0;
            int right=nums.size()-1;
            while(left<right)
            {
                if(left==i)
                {
                    left++;
                    continue;
                }
                else if(right==i)
                {
                    right--;
                    continue;
                }
                if(nums[left]+nums[right]==-1*nums[i])
                {
                    result.insert({nums[min(left,min(right,i))],nums[left+right+i-min(left,min(right,i))-max(left,max(right,i))],nums[max(left,max(right,i))]});
                    left++;
                }
                else if(nums[left]+nums[right]>-1*nums[i])
                {
                    right--;
                }
                else
                {
                    left++;
                }
            }
        }
        vector<vector<int>> final(result.begin(),result.end());
        return final;
    }
};
