class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max_area=INT_MIN;
        int area=0;
        int left=0;
        int right=heights.size()-1;
        while(left<right)
        {
            if(heights[left]<heights[right])
            {
                area=(right-left)*min(heights[left],heights[right]);
                max_area=max(max_area,area);
                left++;
            }
            else
            {
                area=(right-left)*min(heights[left],heights[right]);
                max_area=max(max_area,area);
                right--;
            }
        }
        return max_area;
    }
};
