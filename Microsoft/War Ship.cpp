// War Ship

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	int L, M, res = 0;
	cin >> L >> M;
	
	if(L==0) cout << res;
	res = 1;
	L--;
	
	vector<int> dp(M,0);
	for(int i=0; i<M; i++) dp[i] = (i*i + 1)%M;
	
	queue<int> q;
	q.push(2);
	while(L--){
	    int n = q.size();
	    while(n--){
	        int curr = q.front();
	        q.pop();
	        res += dp[curr];
	        for(int i =0; i<dp[curr]; i++) q.push(i);
	    }
	}
	
	
	cout << res << endl;
	
	return 0;
}
