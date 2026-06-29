class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int nums_xor=0;
        int total_xor=0;
        for(int i=0;i<nums.size();i++)
        {
            nums_xor=nums_xor^nums[i];
            total_xor=total_xor^i;
        }
        total_xor=total_xor^nums.size();
        return nums_xor^total_xor;
    }
};
