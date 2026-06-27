class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int sum=0;
        int left=0;
        int right=k;
        for(int i=0;i<k;i++)
        {
            sum+=abs(arr[i]-x);
        }
        for(int i=0;i<arr.size()-k;i++)
        {
            int pre;
            pre=sum+abs(arr[i+k]-x)-abs(arr[i]-x);
            if(pre<sum)
            {
                sum=pre;
                left=i+1;
                right=i+k+1;
            }
        }
        vector<int> result(arr.begin()+left,arr.begin()+right);
        return result;
    }
};