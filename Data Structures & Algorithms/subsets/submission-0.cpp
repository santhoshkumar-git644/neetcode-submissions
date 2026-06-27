class Solution {
public:
    vector<vector<int>> result;
    void recur(vector<int>& nums,int index,vector<int>cur)
    {
        if(index==nums.size())
        {
            result.push_back(cur);
            return;
        }
        
        recur(nums,index+1,cur);
        cur.push_back(nums[index]);
        recur(nums,index+1,cur);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int index=0;
        vector<int> cur;
        recur(nums,index,cur);
        return result;
    }
};
