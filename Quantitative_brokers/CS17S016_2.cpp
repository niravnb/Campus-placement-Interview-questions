#include <iostream>
#include <cstdlib>
using namespace std;


int solve(int n, int a, int b, vector<int> &s){
    int cost = 0;
    int cntZeros = 0;

    for(auto x:s) if(x==0) cntZeros++;

    int cntOnes = n - cntZeros;
	
	int prevHeight = 1;
	for(int i =1; i<n; i++){
		if((s[i]==s[i-1]){
			if(s[i]==0) cost += a+b;
			else if(s[i]==1) cost += a+2*b;
		}
		else cost += a + prevHeight;
		prevHeight = (s[i]==0)?1:2;
	}
    
	return cost;
}

int main(){
    int n, a, b;
    cin >> n >> a >> b;

    vector<int> s(n);
    for(int i =0; i<n; i++) cin>>s[i];

    int res = solve(n,a,b,s);
    cout << res << endl;
    
    return 0;

}
