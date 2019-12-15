// Research team


#include<bits/stdc++.h>
using namespace std;
int bin[21][21],dist[21][21],n;
struct point{
	int x,y;
};
bool valid(int x,int y)
{
	return x>=1 && x<=5 && y>=1 && y<=8 && bin[x][y]==1;
}
int x[]={-1,0,0,1};
int y[]={0,-1,1,0};
void func(int u,int v)
{
	int i;
	for(i=0;i<4;i++)
	{
		int newx=u+x[i],newy=v+y[i];
		if(valid(newx,newy) && dist[newx][newy]>dist[u][v]+1)
		{
			dist[newx][newy]=dist[u][v]+1;
			func(newx,newy);
		}
	}
}
void init()
{
	int i,j;
	for(i=1;i<=5;i++)
	{
		for(j=1;j<=8;j++)
		dist[i][j]=5000;
	}
}
int main()
{
	cin>>n;
	int i,j;
	for(i=1;i<=5;i++)
	{
		for(j=1;j<=8;j++)
		cin>>bin[i][j];
	}
	struct point p[n];
	for(i=0;i<n;i++)
		cin>>p[i].x>>p[i].y;
	int ans=INT_MAX;
	for(i=0;i<n;i++)
	{
		init();
		dist[p[i].x][p[i].y]=0;
		func(p[i].x,p[i].y);
		int dis=0;
		/*for(i=1;i<=5;i++)
		{
			for(j=1;j<=8;j++)
			cout<<dist[i][j]<<" ";
			cout<<endl;
		}*/
		for(j=0;j<n;j++)
		dis=max(dis,dist[p[j].x][p[j].y]);
		ans=min(ans,dis);
	}
	cout<<ans<<endl;
}
