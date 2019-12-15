// Research team 1

#include<bits/stdc++.h>
using namespace std;
#define isSafe(x,y) x<n && y<n && x>=0 && y >=0 && matrix[x][y]!=0
struct Point{
	// for storing cell co-ordinates
	int x,y ;
};
struct qNode{
	Point p;
	int distance;
};
int main()
 {
  int num_Of_Rare_Element;
  int n;
scanf("%d",&n);
  int matrix[n][n];
  for(int i=0;i<n;i++)
  {
  	for(int j =0;j<n;j++)
      {
  	    scanf("%d",&matrix[i][j]);
      }
  }

  scanf("%d",&num_Of_Rare_Element);

  queue<Point> store_Rare_Element,queue1;
  for(int i=0;i<num_Of_Rare_Element;i++)
  {
  	int x,y;
  	cin>>x>>y;
  	Point point;
  	point.x = x;
  	point.y = y;
  	
  	 queue1.push(point);  // {x,y} is Point I used Initializer list for that
    // it is same as Point p.x= x and p.y=  y;
    store_Rare_Element.push(point) ; // wait till end you will find use of this
  }
  int ansMatrix[n][n]; //  default initial values = 0
  // used for distance update of Rare-elements
memset(ansMatrix,0,sizeof ansMatrix);
  while(!queue1.empty()) // iterate for each Rare_element
  {
    Point sourcePoint =  queue1.front();
    queue1.pop();
// it is used as source for BFS or DFS
//I used BFS for this problem
	bool visited[n][n] ;
	memset(visited,false,sizeof(visited));
	queue<qNode> q;
	qNode qn;
	qn.distance = 0;
	qn.p = sourcePoint ; 
	q.push(qn);
	while(!q.empty())
	{
	  qNode node = q.front();
	  q.pop();
	  Point pt = node.p;
	  int dist = node.distance;
	  int x = pt.x;
	  int y = pt.y;
	/*  now check for all the sides
	i.e right,left,up,down
	  */
	 if(isSafe(x+1,y) && visited[x+1][y]==false)
	   {     visited[x+1][y]=true;
	    	ansMatrix[x+1][y] = max(ansMatrix[x+1][y],dist+1);
	    	Point tempPoint;
	    	tempPoint.x = x+1;
	    	tempPoint.y = y ;
	    	qNode qnode;
	    	qnode.distance = dist+1;
	    	qnode.p= tempPoint;
	 	    q.push(qnode);
	   }
	 if(isSafe(x-1,y) && visited[x-1][y]==false)
	    {   visited[x-1][y]=true;
	        ansMatrix[x-1][y] = max(ansMatrix[x-1][y],dist+1);
	 	    Point tempPoint;
	    	tempPoint.x = x-1;
	    	tempPoint.y = y ;
	    	qNode qnode;
	    	qnode.distance = dist+1;
	    	qnode.p= tempPoint;
	 	    q.push(qnode);
		 }
     if(isSafe(x,y+1) && visited[x][y+1]==false)
	    {   visited[x][y+1]=true;
	 		ansMatrix[x][y+1] = max(ansMatrix[x][y+1],dist+1);
	     	Point tempPoint;
	    	tempPoint.x = x;
	    	tempPoint.y = y+1 ;
	    	qNode qnode;
	    	qnode.distance = dist+1;
	    	qnode.p= tempPoint;
	 	    q.push(qnode);
	    }
	 if(isSafe(x,y-1) && visited[x][y-1]==false)
	    {   visited[x][y-1]=true;
	    	ansMatrix[x][y-1] = max(ansMatrix[x][y-1],dist+1);
	 	    Point tempPoint; // for storing in queue q just formatting for struct qNode
	    	tempPoint.x = x; 
	    	tempPoint.y = y-1 ;
	    	qNode qnode;
	    	qnode.distance = dist+1;
	    	qnode.p= tempPoint;
	 	   	q.push(qnode);
	 	 }
	}
  }
while(!store_Rare_Element.empty())
{
	Point p = store_Rare_Element.front();
	store_Rare_Element.pop();
	ansMatrix[p.x][p.y] = 0; // or you can make it negative
	// it is just to avoid Rare_element location from being selected as
	// Research Centre
}
// Now take the minimum(shortest) from the ansMatrix;
int ans  = INT_MAX;
for(int i=0;i<n;i++)
{
for(int j =0;j<n;j++)
 {
     cout<<ansMatrix[i][j]<<" ";
 	if(ansMatrix[i][j]!=0)
 	ans = min(ans,ansMatrix[i][j]);
	 }
	 cout<<endl;
}
cout<<ans<<endl;
	return 0;
}



