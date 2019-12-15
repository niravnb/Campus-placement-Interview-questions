#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string s,t;
    cin >> s;
    int n = s.length();

    vector<vector<bool>> dp(n+1,vector<bool>(n+1,0));
    int mx = 1, st = 0;

    for(int i = 1; i<=n; i++) dp[i][i] = 1;
    
    for(int i = 0; i<n-1; i++){
        if(s[i] == s[i+1]){
            dp[i][i+1] = 1;
            mx = 2;
            st = i;
        }
    }

    for(int l = 3; l<=n; l++){
        for(int i =0; i<=n-l; i++){
            int j = i+l-1;
            if(s[i]==s[j] && dp[i+1][j-1]){
                dp[i][j]=1;
                mx = l;
                st = i;
            }
        }
    }
    
    cout << s.substr(st,mx) << endl;


    return 0;
}

