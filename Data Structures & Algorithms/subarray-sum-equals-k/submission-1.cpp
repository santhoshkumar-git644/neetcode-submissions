class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int presum=0;
        int result=0;
        vector<int> hash(40000010);
        for(int i=0;i<40000010;i++)
        {
            hash[i]=0;
        }
        hash[20000000]=1;
        for(int i=0;i<nums.size();i++)
        {
            presum+=nums[i];
            
            result+=hash[presum+20000000-k];
            hash[presum+20000000]++;
            cout<<result<<"\n";
        }
        return result;
    }
};