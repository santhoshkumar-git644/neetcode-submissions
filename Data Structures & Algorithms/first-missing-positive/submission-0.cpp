class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<0)
            {
                nums[i]=0;
            }
        }
        for(int i=0;i<nums.size();i++)
        {
            if(abs(nums[i])-1>=0 && abs(nums[i])-1<nums.size())
            {
                if(nums[abs(nums[i])-1]<0)
                {
                    continue;
                }
                else if(nums[abs(nums[i])-1]==0)
                {
                    nums[abs(nums[i])-1]=-1*(nums.size()+2);
                }
                else
                {
                    nums[abs(nums[i])-1]=-1*(nums[abs(nums[i])-1]);
                }
            }
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<0)
            {
                continue;
            }
            else
            {
                return i+1;
            }
        }
        return nums.size()+1;
    }
};