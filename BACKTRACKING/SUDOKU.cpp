class Solution {
private:
    bool isSafe(int row, int col, vector<vector<char>>& board,int val){
        for(int i=0;i<board.size();i++){
            //row check
            if(board[row][i]==val)
                return false;
            //col check
            if(board[i][col]==val)
                return false;
            //3x3 matrix check
            if(board[3*(row/3) + i/3][3*(col/3) + i%3]==val)
                return false;
        }
        return true;
    }

    bool solve(vector<vector<int>>& board){
        int n = board.size();
        for(int row = 0;row<n;row++){
            for(int col = 0;col<n;col++){
                if(board[row][col]== 0){  //0 is for empty place.
                    for(int val = 1;val<=n;val++){
                        if(isSafe(row,col,board,val)){
                            board[row][col] = val;
                            //Recursive Call
                            bool aageSolutionPossible = solve(board);

                            if(aageSolutionPossible)
                                return true;
                            else{
                                //BACKTRACK
                                board[row][col] = 0;
                            }
                        }
                    }
                }
                return false;
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<int>>& board) {
        solve(board); 
    }
};