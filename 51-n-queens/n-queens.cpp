class Solution {
public:
    bool isSafe(vector<string>&board,int row,int col){
        int n =board.size();
        int r =row;
        int c =col;
        while(c>=0){
            if(board[r][c]=='Q') return false;
            c--;
        }
        c=col;
        while(r<n&&c>=0){
            if(board[r][c]=='Q') return false;
            r++;c--;
        }
        r=row;
        c=col;
        while(r<n&&c<n&&r>=0&&c>=0){
            if(board[r][c]=='Q') return false;
            r--;c--;
        }
    return true;
    }
    void helper(vector<string>&board,vector<vector<string>>&res,int col){
        if(col==board.size()){
            res.push_back(board);
            return;
        }
        for(int row=0;row<board.size();row++){
            if(isSafe(board,row,col)){
                board[row][col]='Q';
                helper(board,res,col+1);
                board[row][col]='.';
            }
            
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>res;
        string s(n,'.');
        vector<string>board;
        for(int i=0;i<n;i++){
            board.push_back(s);
        }
        helper(board,res,0);
    return res;
    }
};