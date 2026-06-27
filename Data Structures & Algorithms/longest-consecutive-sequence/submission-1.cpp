class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        if(nums.size()==0)
        {
            return 0;
        }
        for(int i=0;i<nums.size();i++)
        {
            st.insert(nums[i]);
        }
        int max1=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            if(st.find(nums[i]-1)==st.end())
            {
                int count=1;
                int x=nums[i];
                while(st.find(x+1)!=st.end())
                {
                    count++;
                    x++;
                }
                max1=max(max1,count);
                cout<<max1<<"\n";
            }
        }
        return max1;
    }
};
