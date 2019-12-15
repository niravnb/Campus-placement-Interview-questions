// Rock Climbing

#include <iostream>
using namespace std;

void dfs(char *A, int *dp,int n,int m,int i, int j, int r,int c,int max)
{
    if(*(dp+i*m+j)<=max)
        return;
    *(dp+i*m+j)=max;
    //cout<<i<<" "<<j<<" "<<max<<endl;
    //if(i==r && j==c)
    //    return;
    if(j<m-1 && *(A+i*m+j+1)!=' ')
        dfs(A,dp,n,m,i,j+1,r,c,max);
    if(j>0 && *(A+i*m+j-1)!=' ')
        dfs(A,dp,n,m,i,j-1,r,c,max);
    for(int k=i+1;k<n;k++)
    {
        if(*(A+k*m+j)!=' ')
        {
            dfs(A,dp,n,m,k,j,r,c,max>(k-i)?max:k-i);
            break;
        }
    }
    for(int k=i-1;k>=0;k--)
    {
        if(*(A+k*m+j)!=' ')
        {
            dfs(A,dp,n,m,k,j,r,c,max>(i-k)?max:i-k);
            break;
        }
    }
}

int main() {
	int n, m;
	cin>>n;
	cin>>m;
	char A[n][m];
	int r=-1,c=-1;
	char c1;
	cin.get(c1);
	for(int i=0;i<n;i++)
	{
	    for(int j=0;j<m;j++)
	    {
	        cin.get(A[i][j]);
	        if(A[i][j]=='G')
	            r=i,c=j;
	       //cout<<A[i][j];
	    }
	    char c1;
	    cin.get(c1);
	    //cout<<endl;
	}
	for(int i=0;i<n;i++)
	{
	    for(int j=0;j<m;j++)
	    {
	        if(A[i][j]==' ')
	            cout<<'S';
	        else
	            cout<<A[i][j];
	    }
	    cout<<endl;
	}
    int dp[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            dp[i][j]=n;
    }
    //dp[0][0]=0;
    dfs(&A[0][0],&dp[0][0],n,m,n-1,0,r,c,0);
    /*for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<m;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }*/
    cout<<dp[r][c]<<endl;
}
