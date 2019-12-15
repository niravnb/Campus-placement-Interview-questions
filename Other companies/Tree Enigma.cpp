// Tree Enigma

#include<bits/stdc++.h>
using namespace std;

int dfs(bool flag, int u, int prev, vector<unordered_set<int>>& mm, vector<int>& arr,vector<int>& brr, vector<vector<int>>& dp){
	if(dp[flag][u] != -1)
		return dp[flag][u];

	// flip not used at current node, current_flag = previous_flag
	int ret = 0;
	for(auto& v: mm[u])
		if(v == prev)	continue;
		else	ret += dfs(flag, v, u, mm, arr, brr, dp);
	
	if((arr[u]^flag) == brr[u])	return dp[flag][u] = ret;

	//	flip used at current node, current_flag = !previous_flag
	int ret2 = 0;
	for(auto& v: mm[u])
		if(v == prev)	continue;
		else	ret2 += dfs(flag^true, v, u, mm, arr, brr, dp);

	return dp[flag][u] = (1 + min(ret, ret2));
}

int main(){
	int n; cin>>n;
	vector<unordered_set<int>> mm(n);
	for(int i=1; i<n; i++){
		int x, y; cin>>x>>y; x--, y--;
		mm[x].insert(y);
		mm[y].insert(x);
	}
	vector<int> arr(n), brr(n);
	for(int i=0; i<n; i++)
		cin>>arr[i];
	for(int i=0; i<n; i++)
		cin>>brr[i];
	vector<vector<int>> dp(2, vector<int>(n, -1));
	cout<<dfs(false, 0, -1, mm, arr, brr, dp)<<endl;
	
	return 0;
};






// #include<bits/stdc++.h>
// using namespace std;
// vector<vector<int>> graph;
// vector<int> start;
// vector<int> target;
// int result=0;
// int dfs(int root, bool inverted, int parent=-1){
// int cost = 0;

// if(!inverted)
// 	cost = (start[root] != target[root]);
// else
// 	cost = (!start[root] != target[root]);

// for(int i=0; i<graph.size(); i++) 
// 	if(graph[root][i] && i != parent)
// 		cost += min(dfs(i, inverted, root), dfs(i, !inverted, root) + 1);

// return cost;
// }
// int main(){
// int n,x,y;
// cin>>n;
// graph.resize(n, vector<int>(n,0));
// start.resize(n,0);
// target.resize(n,0);

// for (int i = 0; i < n-1; ++i)
// {
// 	cin>>x>>y;
// 	graph[x-1][y-1]=1;
// 	graph[y-1][x-1]=1;
// }

// for (int i = 0; i < n; ++i){
// 	cin>>start[i];
// }

// for (int i = 0; i < n; ++i){
// 	cin>>target[i];

// }

// cout<<min(dfs(0,false), dfs(0, true)+1)<<endl;
// return 0;
// }
