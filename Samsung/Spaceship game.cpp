// Spaceship game

#include<bits/stdc++.h>
using namespace std;
int arr[100][5];
int row,col,possible;
// function to find maximum of 4 numbers
int m1(int a ,int b,int c,int d)
{
    int tmp=-1;
    if(a>tmp) tmp=a;
    if(b>tmp) tmp=b;
    if(c>tmp) tmp=c;
    if(d>tmp) tmp=d;
    return tmp;
}

//function to find maximum of 3 numbers
int m2(int a ,int b,int c)
{
    int tmp=-1;
    if(a>tmp) tmp=a;
    if(b>tmp) tmp=b;
    if(c>tmp) tmp=c;

    return tmp;
}


int dfs(int row1,int col1,int coins,int bomb)
{
   
   // if bomb has no yet been used, this if block will execute
    if (bomb)
    {
    if(!possible)return coins;
        possible=0;
        int brr[row][col];


// storing value of arr in another array brr
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
            brr[i][j]=arr[i][j];


// destroying all enemies in 5 rows above it(including that row)
        for(int i=row1-1;i>row-6;i--)
        {
            if(i<0)break;
            for(int j=0;j<5;j++)
            {
                if(arr[i][j]==2)arr[i][j]=0;
            }
        }
// recursive call keeping bomb ==0
        int t=m2(dfs(row1-1,col1-1,coins,0),dfs(row1-1,col1,coins,0),dfs(row1-1,col1+1,coins,0));



// backtracking all changes previously made
        possible=1;
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
            arr[i][j]=brr[i][j];


        return t;
    }
    
    // if bomb has been previously used then this if block will execute
    if(arr[row1][col1]!=2&&row1>=0&&row1<row&&col1>=0&&col1<col)
    {
     if(arr[row1][col1]==1)
     return m1(dfs(row1-1,col1-1,coins+1,0),dfs(row1-1,col1,coins+1,0),dfs(row1-1,col1+1,coins+1,0),dfs(row1,col1,coins+1,1));
     else return m1(dfs(row1-1,col1-1,coins,0),dfs(row1-1,col1,coins,0),dfs(row1-1,col1+1,coins,0),dfs(row1,col1,coins,1));
    }
    return coins;
}

int main()
{

    cin>>row>>col;
    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
        cin>>arr[i][j];

    possible=1;
    
    // printing maximum of all possible moves
    cout<<m1(/*moving up on same column*/dfs(row-2,2,0,0),/*moving up on next column*/dfs(row-2,3,0,0),/*moving up on previous column*/dfs(row-2,1,0,0),/*staying on same row but exploding bomb*/dfs(row-1,2,0,1))<<endl;



    return 0;
}
/*
7 5
0 0 0 2 1
0 1 0 2 1
2 2 2 2 2
1 0 2 1 1
0 0 2 2 2
1 1 1 1 1
x x S x x
*/

