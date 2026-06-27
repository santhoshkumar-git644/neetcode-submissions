class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int mul=1;
        int zeros=0;
        bool ones=false;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=0)
            {
                ones=true;
            }
            if(nums[i]==0)
            {
                zeros++;
            }
            else
            {
                mul=mul*nums[i];
            }
        }
        if(zeros==1)
        {
            for(int i=0;i<nums.size();i++)
            {
                if(nums[i]==0)
                {
                    if(ones)
                    {
                        nums[i]=mul;
                    }
                    else
                    {
                        nums[i]=0;
                    }
                }
                else
                {
                    nums[i]=0;
                }
            }
        }
        else if(zeros>1)
        {
            for(int i=0;i<nums.size();i++)
            {
                nums[i]=0;
            }
        }
        else
        {
            for(int i=0;i<nums.size();i++)
            {
                nums[i]=mul/nums[i];
            }
        }
        
        return nums;
    }
};
