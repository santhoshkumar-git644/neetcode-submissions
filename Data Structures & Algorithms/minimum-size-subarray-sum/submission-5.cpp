class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if(nums.size()==0)
        {
            return 0;
        }
        if(nums.size()==1)
        {
            if(nums[0]>=target)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        int totalsum=0;
        for(int i=0;i<nums.size();i++)
        {
            totalsum+=nums[i];
        }
        if(totalsum<target)
        {
            return 0;
        }
        int len=INT_MAX;
        int left=0;
        int right=0;
        int sum=nums[0];
        while(left!=nums.size())
        {
            if(right==nums.size()-1)
            {
                if(sum-nums[left]>=target)
                {
                    sum=sum-nums[left];
                    len=min(len,right-left);
                    cout<<sum<<"\n";
                }
                else
                {
                    break;
                }
                left++;
                continue;
            }
            if(sum<target)
            {
                right++;
                sum+=nums[right];
                if(sum>=target)
                {
                    len=min(len,right-left+1);
                }
                cout<<sum;
            }
            else
            {
                len=min(len,right-left+1);
                sum-=nums[left];
                left++;
            }
        }
        return len;
    }
};