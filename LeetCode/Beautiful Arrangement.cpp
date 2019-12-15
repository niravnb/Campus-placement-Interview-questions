// Beautiful Arrangement

class Solution {
public:
    int ans =0;
    int n;
    void solve(vector<bool> &vis, int ind){
        if(ind > n){
            ans++;
            return;
        }
        for(int i = 1; i<=n; i++){
            if(!vis[i] && (i%ind==0 || ind%i==0)){
                vis[i] = true;
                solve(vis,ind+1);                
                vis[i] = false;                
            }
        }
    }
    
    
    int countArrangement(int N) {
        vector<bool> vis(N+1,false);
        n = N;
        
        solve(vis, 1);
        
        return ans;
    }
};
