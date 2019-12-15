class Solution {
public:
    int n;
    int fun(int r1, int c1, int c2, vector<vector<vector<int>>> &dp, vector<vector<int>>& grid){
        int r2 = r1 + c1 - c2;
        if(r1>=n || r2>=n || c1>=n || c2>=n || grid[r1][c1]==-1 || grid[r2][c2] == -1 ){
            return INT_MIN + 2;
        }else if(dp[r1][c1][c2] != INT_MIN){
            return dp[r1][c1][c2];
        }else if((r1==n-1 && c1==n-1) || (r2==n-1 && c2==n-1)){
            return grid[n-1][n-1];
        }else{
            int ans = grid[r1][c1];
            if(c1 != c2) ans += grid[r2][c2];
            ans += max(fun(r1+1,c1, c2, dp, grid), max(fun(r1, c1+1, c2+1, dp, grid), max(fun(r1+1, c1, c2+1, dp, grid),fun(r1, c1+1, c2, dp, grid))));
            return dp[r1][c1][c2] = ans;
        }
    }
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n, vector<int>(n, INT_MIN)));
        
        return max(0, fun(0,0,0, dp, grid));
        
    }
};