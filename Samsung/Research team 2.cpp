// Research team 2
#include <bits/stdc++.h>
using namespace std;

struct E{
    int x,y;
}elem[5];

class Queue{
    public:
    E A[100000];
    int front,rear;
    Queue()
    {
        front = rear = 0;
    }
    void push(E e){
        A[rear].x = e.x;
        A[rear].y = e.y;
        rear++;
    }
    E pop(){
        return A[front++];
    }
    bool isEmpty(){
        return front>=rear?1:0;
    }
};

int n,num,dist[20][20];
bool M[20][20];


bool isValid(int x,int y){
    if(x>=0 && x<n && y>=0 && y<n && M[x][y]==1)
        return 1;
    return 0;
}

void bfs(int x,int y){
    Queue q;
    bool vis[20][20];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            vis[i][j] = 0;
        }
    E n;
    n.x = x;
    n.y = y;
    vis[x][y] = 1;
    dist[x][y] = 0;
    q.push(n);
    int xx[] = {1,0,0,-1};
    int yy[] = {0,1,-1,0};
    while(!q.isEmpty()){
       	E n = q.pop();
       	//cout<<n.x<<" "<<n.y<<endl;
        //cout<<"bug"<<endl;
        for(int i=0;i<4;i++){
            int xnew = n.x+xx[i];
            int ynew = n.y+yy[i];
            if(isValid(xnew, ynew) && !vis[xnew][ynew]){
                //cout<<"bug"<<endl;
                dist[xnew][ynew] = dist[n.x][n.y]+1;
                E nn;
                nn.x = xnew, nn.y = ynew;
                vis[nn.x][nn.y] = 1;
                q.push(nn);
            }
        }
    }/*
    cout<<x<<" 1 "<<y<<endl;
    for(int i=0;i<num;i++)
    {
    	cout<<dist[elem[i].x][elem[i].y]<<" ";
    }
    cout<<endl;*/
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>M[i][j];
    cin>>num;
    for(int i=0;i<num;i++)
        cin>>elem[i].x>>elem[i].y;
    int res=999999;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(M[i][j]==1){
                bfs(i,j);
                int ans = 0;
                for(int k=0;k<num;k++){
                    ans = max(ans,dist[elem[k].x][elem[k].y]);
                }
                res = min(res,ans);
            }
        }
    }
    cout<<res<<endl;
	return 0;
}
