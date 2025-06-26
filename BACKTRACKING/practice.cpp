class Solution {
    private:
        void solve(int x,int yvector<vector<int>> mat,vector<vector<int>> &visited,vector<string>& ans,string path, int n){
            if(x==n-1 && y==n-1){
                ans.push_back(path);
                return;
            }
            //D
            if(isSafe(x+1,y,mat,visited)){
                visited[x][y]=1;
                solve(x+1,y,mat,visited,ans,path+"D",n);
            }
            //l
            //R
            //U

            // backtracking
            visited[x][y] = 0;
        }
    public:
      vector<string> findPath(vector<vector<int>> &mat) {
          int n = mat.size();
          vector<string>ans;
          string path;
          vector<vector<int>>visited(n,vector<int>(n,0));

          solve(0,0,mat,visited,ans,path,n);
      }
  };