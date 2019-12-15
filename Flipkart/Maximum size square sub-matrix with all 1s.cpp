// Maximum size square sub-matrix with all 1s 

#include <bits/stdc++.h> 
using namespace std; 


int printMaxSubSquare(vector<vector<int>> M)

{
    int R = M.size();
    int C = M[0].size();
    
    int i,j; 
    int S[R][C]; 
    int max_of_s, max_i, max_j; 
    
    /* Set first column of S[][]*/
    for(i = 0; i < R; i++) 
        S[i][0] = M[i][0]; 
    
    /* Set first row of S[][]*/
    for(j = 0; j < C; j++) 
        S[0][j] = M[0][j]; 
        
    /* Construct other entries of S[][]*/
    for(i = 1; i < R; i++) 
    { 
        for(j = 1; j < C; j++) 
        { 
            if(M[i][j] == 1) 
                S[i][j] = min(S[i][j-1],min( S[i-1][j], 
                                S[i-1][j-1])) + 1; 
            else
                S[i][j] = 0; 
        } 
    }
    int val = INT_MIN;
    for(int i = 0; i < R;i++ )
    for(int j = 0; j < C; j++){
        val = max(val, S[i][j]);
    }
    return val;
    
} 

