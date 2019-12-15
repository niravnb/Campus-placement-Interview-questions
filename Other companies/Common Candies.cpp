// Common Candies

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'countCandies' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER friends_nodes
 *  2. INTEGER_ARRAY friends_from
 *  3. INTEGER_ARRAY friends_to
 *  4. INTEGER_ARRAY friends_weight
 */

int find(int a, vector<int> &par){
    if(par[a]!=a){
        par[a] = find(par[a], par);
    }
    return par[a];
}

void un(int a, int b, vector<int> &par, vector<int> &rank){
    int x = find(a, par);
    int y = find(b, par);
    if(x == y ) return;
    if(rank[x] >= rank[y]){
        par[y] = x;
        rank[x] += rank[y];
    }else{
        par[x] = y;
        rank[y] += rank[x];
    }
}


int countCandies(int friends_nodes, vector<int> friends_from, vector<int> friends_to, vector<int> friends_weight) {

int n = friends_nodes;
unordered_map<int, vector<pair<int,int>>> mp;

for(int i =0; i<friends_from.size(); i++){
    int k = friends_weight[i];
    int u = friends_from[i];
    int v = friends_to[i];
    mp[k].push_back({u,v});
}
long long int res = LLONG_MIN;
long long int mx_comp = LLONG_MIN;
vector<pair<long long int,long long int>> rest;
for(auto it : mp){
    auto adj = it.second;
    
    // for(auto x: adj) cout << x.first << "  " << x.second;
    // cout <<endl;
    vector<int> par(n+1,0);
    vector<int> rank(n+1,1);
    for(int i =0; i<=n; i++) par[i] = i;

    for(auto x: adj){
        int u = x.first, v= x.second;
        un(u,v,par,rank);
    }

    // cout << "rank--" << it.first<< endl;
    // for(auto x: rank) cout << x << " ";

    // , lar_comp = 0;
    vector<int> lar_comp;
    for(int i =0; i<=n; i++){
        if(rank[i] >= mx_comp){
            mx_comp = rank[i];
            lar_comp.push_back(i);
        }
    }
    // if(lar_comp.size()>0){
        for(int it = 0; it<lar_comp.size(); it++){
            int lar = lar_comp[it];
            vector<int> A;
            for(int i = 0; i<=n; i++){
                if(par[i]==lar){
                    A.push_back(i);
                }
            }

            sort(A.begin(), A.end());
            int An = A.size();
            if(An>=2){
                res = max(res, (long long int)A[An-1]*A[An-2]);
                rest.push_back({mx_comp,(long long int)A[An-1]*A[An-2]});
            }
        }
        
    // }
    
    




}

sort(rest.begin(), rest.end(), greater<pair<int,int>>());
// for(int i =0; i<rest.size(); i++){

// }

return rest[0].second;

// return res;
}
int main()