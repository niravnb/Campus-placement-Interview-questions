// Modify 0-1 knapsack

#include <bits/stdc++.h>
using namespace std;

int knapsack(int arr[],int n, int k)
{
   
   int dp[n+1][k+1]; 
   // Base Cases
   for (int i=0;i<=n;i++)
   {
       dp[i][0]=0;
   }
   
   for(int j=0;j<=k;j++)
   {
       dp[0][j]=0;
   }
    
   for (int i = 1,j=0; j <=k ; j++)
   {
      if(j>=arr[i])
      {
          dp[i][j]=max(arr[i],dp[i-1][j]);
      }
      else
      {
          dp[i][j]=dp[i-1][j];
      }
   } 

   // Actual Code
   for(int i=2;i<=n;i++)
   {
       for(int j=2;j<=k;j++)
       {
          if(j>=arr[i])
          {
              dp[i][j]=max(arr[i]+dp[i-2][j-arr[i]],dp[i-1][j]);
          }
          else
          {
              dp[i][j]=dp[i-1][j];
          }
       }
   }
    
   return dp[n][k];
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int arr[501];

    int T;
    cin >> T;
    while(T--)
    {
        int n,k;
        cin >> n >> k;        
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }
        
        cout << knapsack(arr,n,k) << endl;
    }

    return 0;
}
