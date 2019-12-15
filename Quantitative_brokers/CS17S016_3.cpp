#include <iostream>
#include <bits/stdc++.h>
using namespace std;


bool sortcol( const vector<int>& a, 
              const vector<int>& b ) { 
    if(a[0]==b[0]) return a[1] < b[1];
    return a[0] < b[0];
} 

vector<int> solve(vector<vector<int>> &m){
    int n = m[0].size();
    vector<int> res;
    
    vector<vector<int>> mat(n, vector<int>(4,0));
    for(int i =0; i<n; i++){
        for(int j=0; j<4; j++){
            mat[i][j] = m[j][i];
        }
    }
    
    // Sorting by x1, y1
    sort(mat.begin(), mat.end(), sortcol);
    
    int x1 = mat[0][0];
    int y1 = mat[0][1];
    int x2 = mat[0][2];
    int y2 = mat[0][3];
    int x3,y3,x4,y4,x5,y5,x6,y6;
    for(int j = 1; j<n; j++){
        x3 = mat[j][0];
        y3 = mat[j][1];
        x4 = mat[j][2];
        y4 = mat[j][3];
        
        // gives bottom-left point 
        // of intersection rectangle 
        x5 = max(x1, x3); 
        y5 = max(y1, y3); 
      
        // gives top-right point 
        // of intersection rectangle 
        x6 = min(x2, x4); 
        y6 = min(y2, y4); 
        
        // no intersection 
        if (x5 > x6 || y5 > y6) { 
            continue;
        }else{
            res = {x5,y5};
        }
        x1 = x5;
        y1 = y5;
        x2 = x6;
        y2 = y6;
    }
    
    
    return res;
}

int main(){
    int n;
    cin >> n;
    
    vector<vector<int>> mat(4,vector<int>(n));
    
    for(int i =0; i<n; i++){
        for(int j=0; j<4; j++){
            cin >> mat[j][i];
        }
    }
    
    vector<int> res = solve(mat);
    cout << res[0] << " " << res[1] << endl;

    return 0;

}
