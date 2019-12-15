#include<bits/stdc++.h>
using namespace std;

long long dfs(unordered_map<string,int> &mp, vector<vector<long long> > &adj, vector<long long> &honesty, long long type, long long node, long long depth ,long long k){
    if(depth == k){
        if(type==1) return honesty[node]%2==0;
        else return honesty[node]%3==0;
    }
    long long r = 0;
    
    
   
          
    
    for(auto x: adj[node]){
        string key = to_string(x)+'_'+to_string(type)+'_'+to_string(k-depth-1);
            if(mp.find(key)==mp.end()){
              mp[key] = dfs(mp, adj, honesty,type, x, depth+1, k);
            } 
          r += mp[key];
      }
      string kk = to_string(node)+'_'+to_string(type)+'_'+to_string(k-depth);
      mp[kk] = r;
      
      return r;
    
}
vector<long long> solve (int N,int Q,vector<vector<long long> > query, vector<long long> honesty, vector<long long> parent) {
   // Write your code here
  vector<vector<long long> > adj(N);
   
  for(int i =0; i<N; i++){
      int p = parent[i];
      if(p != 0){
          adj[--p].push_back(i);
      }
  }
   
//   for(auto x: adj){
//       for(auto y:x) cout << y << " ";
//       cout << endl;
//   }
   
   unordered_map<string,int> mp;
   
  vector<long long> res;
  for(int q = 0; q<Q; q++){
      int type = query[q][0];
      int node = query[q][1];
      int k = query[q][2];
      
      long long r = 0;
      for(auto x: adj[--node]){
          string key = to_string(x)+'_'+to_string(type)+'_'+to_string(k-1);
   
          if(mp.find(key)==mp.end()){
              mp[key] = dfs(mp, adj, honesty,type, x, 1, k);
          } 
          r += mp[key];
          
        
      }
      
      string kk = to_string(node)+'_'+to_string(type)+'_'+to_string(k);
      mp[kk] = r;

       res.push_back(r);
       
  }
   
  return res;
   
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<long long> honesty(N);
    for(int i_honesty=0; i_honesty<N; i_honesty++)
    {
    	cin >> honesty[i_honesty];
    }
    vector<long long> parent(N);
    for(int i_parent=0; i_parent<N; i_parent++)
    {
    	cin >> parent[i_parent];
    }
    int Q;
    cin >> Q;
    int X;
    cin >> X;
    vector<vector<long long> > query(Q, vector<long long>(X));
    for(int i=0; i<Q; i++)
    {
    	for(int j=0; j<X; j++)
    	{
    		cin >> query[i][j];
    	}
    }

    vector<long long> out_;
    out_ = solve(N,Q,query, honesty, parent);
    cout << out_[0];
    for(int i_out_=1; i_out_<out_.size(); i_out_++)
    {
    	cout << " " << out_[i_out_];
    }
}