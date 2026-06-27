class Solution {
public:
    int findMin(vector<int> &nums) {
        int left=0;
        int right=nums.size()-1;
        int mid;
        int mini=nums[0];
        int count=0;
        while(left<=right)
        {
            mid=(left+right)/2;
            if(nums[mid]<nums[0])
            {
                mini=min(nums[mid],mini);
                right=mid-1;
            }
            else
            {
                mini=min(nums[mid],mini);
                left=mid+1;
            }
        }
        return mini;
    }
};