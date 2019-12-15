// Distorted Palindrome

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	string s;
	while(1){
	    cin >> s;
	    if(s=="0") break;
	    int n = s.length();
	    int count_odds = 0, res = 0;
	    
	    unordered_map<char,int> mp;
	    for(int i =0; i<n; i++) mp[s[i]]++;
	    for(auto x: mp){
	        if(x.second%2==1) count_odds++;
	    }
	    
	    if(count_odds>1) cout << "Impossible" << endl;
	    else{
	        for(int i=0; i<n/2; i++){
	            if(s[i]!=s[n-1-i]){
	                int j = i+1, k = n-i-2;
	                
	                while(s[j]!=s[n-1-i]) j++;
	                while(s[i]!=s[k]) k--;
	                
	                res+=min(j-i,n-i-1-k);
	                
	                if(j-i<=n-i-1-k){
	                    char tmp = s[j];
	                    for(;j>i;j--) s[j] = s[j-1];
	                    s[i] = tmp;
	                }else{
	                    char tmp = s[k];
	                    for(;k<n-1-i;k++) s[k] = s[k+1];
	                    s[n-1-i] = tmp;
	                }
	                
	            }
	        }
	        cout << res << endl;
	    }
	    
	}
	
	return 0;
}
