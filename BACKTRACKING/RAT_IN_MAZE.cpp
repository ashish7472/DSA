class Solution {
  private:
  
    bool isSafe(int newX,int newY,vector<vector<bool>> &vis,vector<vector<int>> &mat,int n){
        if((newX>=0 && newX<n) && (newY>=0 && newY<n) && vis[newX][newY]==0 && mat[newX][newY]==1)
            return 1;
        else
            return 0;
    }
    
    void solve(int x,int y,vector<vector<int>> &mat,int n,vector<string> &ans,vector<vector<bool>> &vis,string path){
        
        if(x==n-1 && y==n-1){
            ans.push_back(path);
            return;
        }
        
        //Down
        if(isSafe(x+1,y,vis,mat,n)){
            vis[x][y] = 1;
            solve(x+1,y,mat,n,ans,vis,path+'D');
        }
        //Left
        if(isSafe(x,y-1,vis,mat,n)){
            vis[x][y] = 1;
            solve(x,y-1,mat,n,ans,vis,path+'L');
        }
        //Right
        if(isSafe(x,y+1,vis,mat,n)){
            vis[x][y] = 1;
            solve(x,y+1,mat,n,ans,vis,path+'R');
        }
        //Up
        if(isSafe(x-1,y,vis,mat,n)){
            vis[x][y] = 1;
            solve(x-1,y,mat,n,ans,vis,path+'U');
        }
        
        vis[x][y] = 0; //BACKTRACKING (recursion)
        
    }
  public:
    vector<string> findPath(vector<vector<int>> &mat) {
        int n = mat.size();
        vector<string>ans;
        if(mat[0][0]==0)
            return ans;
        
        vector<vector<bool>>vis(n,vector<bool>(n,0));
        string path = "";
        
        solve(0,0,mat,n,ans,vis,path);
        return ans;
    }
};