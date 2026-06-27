class Solution {
public:
int pres=0;
    void dfs(vector<vector<int>>& grid,int row,int column)
    {
        if(row>=grid.size() || column>=grid[0].size() || row<0 || column<0 || grid[row][column]==0)
        {
            return;
        }
        pres++;
        grid[row][column]=0;
        dfs(grid,row+1,column);
        dfs(grid,row,column+1);
        dfs(grid,row-1,column);
        dfs(grid,row,column-1);
        return;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int count=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    dfs(grid,i,j);
                    count=max(count,pres);
                    pres=0;
                }
            }
        }
        return count;
    }
};
