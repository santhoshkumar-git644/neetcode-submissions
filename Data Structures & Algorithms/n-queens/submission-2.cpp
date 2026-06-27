class Solution {
public:
    bool attack(vector<string> board,int row,int column)
    {
        for(int i=0;i<board.size();i++)
        {
            if(board[row][i]=='Q')
            {
                return true;
            }
            if(board[i][column]=='Q')
            {
                return true;
            }
        }
    int n = board.size();

for(int i = row, j = column; i >= 0 && j >= 0; i--, j--)
{
    if(board[i][j] == 'Q')
        return true;
}

for(int i = row + 1, j = column + 1; i < n && j < n; i++, j++)
{
    if(board[i][j] == 'Q')
        return true;
}

for(int i = row, j = column; i >= 0 && j < n; i--, j++)
{
    if(board[i][j] == 'Q')
        return true;
}

for(int i = row + 1, j = column - 1; i < n && j >= 0; i++, j--)
{
    if(board[i][j] == 'Q')
        return true;
}
        
        return false;
    }
    vector<vector<string>> result;
    void solve(vector<string> board,int n,int count,int row,int column)
    {
        if(count==n)
        {
            result.push_back(board);
            return ;
        }
            for(int j=0;j<board.size();j++)
            {
                if(!attack(board,row,j) && board[row][j]=='.')
                {
                    board[row][j]='Q';
                    
                    solve(board,n,count+1,row+1,0);
                    board[row][j]='.';
                }
            }
        return ;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board;
        string s;
        for(int i=0;i<n;i++)
        {
            s+='.';
        }
        for(int i=0;i<n;i++)
        {
            board.push_back(s);
        }
        solve(board,n,0,0,0);
        return result;
    }
};
