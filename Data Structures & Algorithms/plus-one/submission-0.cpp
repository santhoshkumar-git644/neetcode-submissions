class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=1;
        vector<int> result;
        for(int i=digits.size()-1;i>=0;i--)
        {
            int sum=digits[i]+carry;
            result.push_back(sum%10);
            carry=sum/10;
        }
        if(carry==1)
        {
            result.push_back(1);
        }
        reverse(result.begin(),result.end());
        return result;
    }
};
