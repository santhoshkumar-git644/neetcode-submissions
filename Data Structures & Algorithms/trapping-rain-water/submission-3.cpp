class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        vector<int> nge;
        vector<int> pge;
        int maxi=-1;
        int area=0;
        for(int i=0;i<height.size();i++)
        {
            pge.push_back(maxi);
            maxi=max(maxi,height[i]);
        }
        maxi=-1;
        for(int i=height.size()-1;i>=0;i--)
        {
            nge.push_back(maxi);
            maxi=max(maxi,height[i]);
        }
        reverse(nge.begin(),nge.end());
        for(int i=0;i<height.size();i++)
        {
            if((min(pge[i],nge[i])-height[i])<0)
            {
                continue;
            }
            else
            {
                area+=min(pge[i],nge[i])-height[i];
            }
            cout<<area;
        }
        return area;
    }
};
