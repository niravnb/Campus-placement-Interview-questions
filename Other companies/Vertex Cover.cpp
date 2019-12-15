// Vertex Cover

#include <bits/stdc++.h>
using namespace std;

map<int,vector<int>> adj;
vector<int> dp0,dp1,dp2;

void vcover(int u, int Pu)
{
	int a = 0, b = 0, c = 0, ans = 1e6;
	for(int i=0;i<adj[u].size();i++)
	{
		int v = adj[u][i];
		if(v==Pu)
		    continue; 
		vcover(v,u);
		a += dp1[v];
		b += min(dp1[v],dp2[v]);
		c += min(dp0[v],min(dp1[v],dp2[v]));		
	}
	
	for(int i=0;i<adj[u].size();i++)
	{
		int v = adj[u][i];
		if(v==Pu)
		    continue;
		ans = min(ans,b-min(dp1[v],dp2[v])+dp2[v]);
	}
	dp0[u] = a;
	dp1[u] = ans;
	dp2[u] = 1 + c;
}

int main(){
	int n,m;
	cin>>n>>m;
	dp0.resize(n+1);
	dp1.resize(n+1);
	dp2.resize(n+1);
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	vcover(1,0);
	cout<<min(dp1[1],dp2[1])<<endl;
	

	return 0;
}
