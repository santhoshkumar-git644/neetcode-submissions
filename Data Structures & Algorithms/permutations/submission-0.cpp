class Solution {
public:
    vector<vector<int>> result;
    void recur(vector<int> nums,vector<int> present,vector<int>hash,int count)
    {
        if(count==nums.size())
        {
            cout<<"hi";
            result.push_back(present);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(!hash[nums[i]+10])
            {
                hash[nums[i]+10]=1;
                present.push_back(nums[i]);
                recur(nums,present,hash,count+1);
                present.pop_back();
                hash[nums[i]+10]=0;
            }
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> hash(21,0);
        vector<int> present;

        recur(nums,present,hash,0);
        return result;
    }
};
