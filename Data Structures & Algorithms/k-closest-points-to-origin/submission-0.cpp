class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>result;
        priority_queue<
    pair<int,int>,
    vector<pair<int,int>>,
    greater<pair<int,int>>
> qu;
        for(int i=0;i<points.size();i++)
        {
            int distance=points[i][0]*points[i][0]+points[i][1]*points[i][1];
            qu.push({distance,i});
        }
        for(int i=0;i<k;i++)
        {
            result.push_back(points[qu.top().second]);
            qu.pop();
        }
        return result;
    }
};
