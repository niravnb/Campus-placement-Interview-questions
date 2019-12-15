// Maximum Sub-square Matrix
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


/*
 * Complete the 'largestSubgrid' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. 2D_INTEGER_ARRAY grid
 *  2. INTEGER maxSum
 */

int largestSubgrid(vector<vector<int>> grid, int maxSum) {
    int n = grid.size(), m = grid[0].size();
    long long int res = 0;
    long long int mx = LLONG_MIN, mn = LLONG_MAX, total=0;
    for(int i=0; i<n; i++){
        for(int j =0; j<n; j++){
            total += grid[i][j];
            mx = max(mx, (long long int)grid[i][j]);
            mn = min(mn, (long long int)grid[i][j]);
        }
    }

    if(maxSum >= total) return n;
    else if(maxSum < mx) return 0;
    else if(maxSum == mx) return 1;
    else{

        if(maxSum>= mx) res++;
        vector<vector<long long int>> dp(n, vector<long long int>(n,0));
        for(int r=0; r<n; r++){
            for(int c=0; c<n; c++){
                if(r==0 && c==0) dp[r][c] = grid[r][c];
                else if(r==0) dp[r][c] = grid[r][c];
                else dp[r][c] = dp[r-1][c] + grid[r][c];
            }
        }

        for(int r=0; r<n; r++){
            for(int c=1; c<n; c++){
                dp[r][c] = dp[r][c-1] + dp[r][c];
            }
        }

        // for(auto x: dp){
        //     for(auto y:x) cout << y << " ";
        //     cout << endl;
        // }
        for(int k = n-1; k>1; k--){
            int r = k-1, c = k-1;
            long long int cur_max = LLONG_MIN;
            for(;r<n; r++){
                c = n-k;
                for(;c<n; c++){
                    if(r-k>=0 && c-k>=0) cur_max = max(cur_max, dp[r][c] - dp[r-k][c] - dp[r][c-k] + dp[r-k][c-k]);
                    else if(c-k>=0) cur_max = max(cur_max, dp[r][c] - dp[r][c-k]);
                    else if(r-k>=0) cur_max = max(cur_max, dp[r][c] - dp[r-k][c]);
                    else cur_max = max(cur_max, dp[r][c]);
                }
            }
            if(cur_max <= maxSum){
                res = k;
                return res;
            }
        }

        return res;
    }
}
