#include <bits/stdc++.h>

using namespace std;
using nagai=long long;
#define sz(x) int((x).size())

const int N=500;
string matr[N];
vector<pair<int,int>>g[N];
int used[N];
vector<int>cur;
int ans1;
void d(int u,bool ch){
	if(used[u])return;
	used[u]=true;
	cur.push_back(u);
	if(ch)
		++ans1;
	for(auto p:g[u]){
		d(p.first,ch^p.second);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	for(int test=1;test<=t;++test){
		 cout<<"Case #"<<test<<": ";
		 int n;
		 cin>>n;
		 for(int i=0;i<n;++i)cin>>matr[i];
		 int cnt1=n+n-1;
		 for(int i=0;i<N;++i)g[i].clear();
		 for(int i=0;i<n;++i)
			 for(int j=0;j<n;++j){
				 int num1=i+j;
				 int num2=cnt1+i+(n-j-1);
				 g[num1].emplace_back(num2,matr[i][j]=='.');
				 g[num2].emplace_back(num1,matr[i][j]=='.');
			 }
		 int ans=0;
		 memset(used,0,sizeof used);
		 for(int i=0;i<n;++i)
			 for(int j=0;j<n;++j){
				 int num1=i+j;
				 int num2=cnt1+i+(n-j-1);
				 if(matr[i][j]=='.'&&!used[num1]){
					 cur.clear();
					 ans1=0;
					 d(num1,true);
					 int ans2=ans1;
					 ans1=0;
					 for(int x:cur)used[x]=false;
					 d(num2,true);
					 ans+=min(ans1,ans2);
				 }
			 }
		 cout<<ans<<'\n';
	}
	return 0;
}

