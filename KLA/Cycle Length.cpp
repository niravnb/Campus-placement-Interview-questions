#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


/*
 * Complete the 'findCriticalRoads' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY roads as parameter.
 */

int findCriticalRoads(vector<vector<int>> roads) {
    int mx = -1;
    for(auto x: roads){
            int u = x[0], v = x[1];
            mx = max({mx, u,v});
    }

    int n = roads.size();
    vector<int> deg(mx+1,0);
    vector<vector<int>> adj(mx+1);
    for(auto x: roads){
            int u = x[0], v = x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            deg[v]++;
            deg[u]++;
    }

    int res = 0;

    int flag = true;
    while(flag){
        flag = false;
        vector<int> tmp;
        for(int i = 0; i<=mx; i++){
            if(deg[i]==1){
                res++;
                deg[i]=0;
                for(auto x: adj[i]){
                    deg[x]--;
                    if(deg[x]==1) flag = true;
                }
            }
        }
    }
    return res;

}

int main()