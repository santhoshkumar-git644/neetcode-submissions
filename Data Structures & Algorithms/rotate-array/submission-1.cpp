class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> result;
        if(k>nums.size())
        {
            k=k%nums.size();
        }
        int left=0;
        int right=nums.size()-k;
        for(int i=0;i<nums.size();i++)
        {
            if(k!=0)
            {
                result.push_back(nums[right]);
                right++;
                k--;
            }
            else
            {
                result.push_back(nums[left]);
                left++;
            }
        }
        nums=result;
    }
};