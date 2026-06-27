class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> qu;
        qu.push({0,0,0});
        vector<vector<int>> dist(heights.size(),vector<int>(heights[0].size(),INT_MAX));
        dist[0][0]=0;
        while(!qu.empty())
        {
            int height=qu.top()[0];
            int present_row=qu.top()[1];
            int present_col=qu.top()[2];
            qu.pop();
            if(height>dist[present_row][present_col])
            {
                continue;
            }
            vector<int> neighbouring_row={-1,0,1,0};
            vector<int> neighbouring_col={0,-1,0,1};
            for(int i=0;i<4;i++)
            {
                int next_row=present_row+neighbouring_row[i];
                int next_col=present_col+neighbouring_col[i];
                if(next_row>=0 && next_row<heights.size() && next_col>=0 && next_col<heights[0].size())
                {
                    int diff=max(height,abs(heights[next_row][next_col]-heights[present_row][present_col]));
                    if(diff<dist[next_row][next_col])
                    {
                        dist[next_row][next_col]=diff;
                        qu.push({diff,next_row,next_col});
                    }
                }
            }
        }
        return dist[heights.size()-1][heights[0].size()-1];
    }
};