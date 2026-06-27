class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len=nums.size();
        vector<int> prefix(len);
        vector<int> postfix(len);
        prefix[0]=nums[0];
        
        postfix[len-1]=nums[len-1];
        for(int i=1;i<len;i++)
        {
            prefix[i]=prefix[i-1]*nums[i];
            postfix[len-1-i]=postfix[len-i]*nums[len-i-1];
        }
        nums[0]=postfix[1];
        nums[len-1]=prefix[len-2];
        for(int i=1;i<len-1;i++)
        {
            nums[i]=postfix[i+1]*prefix[i-1];
        }
        return nums;
    }
};
