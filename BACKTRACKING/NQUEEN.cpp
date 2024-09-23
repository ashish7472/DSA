class Solution {
private:

//there can be an optimization by using hashmap in isSafe function by reducing it in O(1).
    bool isSafe(int row, int col, vector<vector<int>>& board, int n){
        int x = row;
        int y = col;

        //check for same row
        //hum sirf piche wali posi pe hi check kr rhe h qki jis pos pe rkhna chate h uske aage to Q hogi hi nhi couz we filling from left to right
        //and same col me do hongi hi nhi to q ke corresponding col me bhi nhi check kr rhe
        while(y>=0){
            if(board[x][y]==1)
                return false;
            y--;
        }

        x = row;
        y = col;
        //check for upper left diagnol
        while(x>=0 && y>=0){
            if(board[x][y]==1)
                return false;
            x--,y--;
        }

        x = row;
        y = col;
        //check for lower left diagnol
        while(x<n && y>=0){
            if(board[x][y]==1)
                return false;
            x++,y--;
        }

        return true;
    }

    void addSolution(vector<vector<int>> &board,vector<vector<int>> &ans,int n){
        vector<int>temp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                temp.push_back(board[i][j]);
            }
        }
        ans.push_back(temp);
    }

    void solve(int col,vector<vector<int>> &ans,vector<vector<int>> &board,int n){
        //base case
        if(col == n){
            addSolution(board,ans,n);
            return;
        }

        //solve for one col and for this one col we have to traverse all rows
        for(int row = 0;row<n;row++){
            if(isSafe(row,col,board,n)){
                board[row][col] = 1;
                solve(col+1,ans,board,n); //recursive call for next col.
                board[row][col] = 0; //BACKTRACK
            }
        }

    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> board(n,vector<int>(n));
        vector<vector<int>>ans;

        solve(0,ans,board,n); // 0 is representing column
        return ans;
    }
};