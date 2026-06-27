class Solution {
public:
    void dfs(vector<vector<char>>& grid,int row,int column)
    {
        if(row>=grid.size() || column>=grid[0].size() || row<0 || column<0 || grid[row][column]=='0')
        {
            return;
        }
        grid[row][column]='0';
        dfs(grid,row+1,column);
        dfs(grid,row,column+1);
        dfs(grid,row-1,column);
        dfs(grid,row,column-1);
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1')
                {
                    dfs(grid,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};
