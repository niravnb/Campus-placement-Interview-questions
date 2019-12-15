#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;
int main() {
/* Enter your code here. Read input from STDIN. Print output to STDOUT */
int n1, n2;
cin >> n1 >> n2;
string s1, s2, s, t;
cin >> s1 >> s2;

s = s1+s2;
t = s;
reverse(t.begin(), t.end());
int n = n1+n2;
vector<vector<int>> dp(n+1, vector<int>(n+1,0));
int res = 0;

for(int i = 1; i<=n; i++){
    for(int j=1; j<=n; j++){
        if(s[i-1]==t[j-1]){
            dp[i][j] = 1 + dp[i-1][j-1];
        }else{
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
}


cout << dp[n][n] << endl;

return 0;
}

