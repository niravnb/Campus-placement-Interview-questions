#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int main() {
/* Enter your code here. Read input from STDIN. Print output to STDOUT */
string A, res;
cin >> A;
vector<int> bt(100000000);
long long int n = A.length(), mx_rep = 0;

for(int i =0; i<=n-5; i++){
    long long int pt = 0;
    string tmp = "";
    for(int j = 0; j<5; j++){
        pt = 26*pt + (A[i+j]-'a');
        tmp += A[i+j];
    }
    bt[pt]++;
    if(bt[pt] > mx_rep){
        mx_rep = bt[pt];
        res = tmp;
    }else if(bt[pt] == mx_rep){
        if(tmp < res) res = tmp;
    }
}


// unordered_map<string, long long int> mp;
// long long int n = A.length();
// for(int i =0; i<=n-5; i++){
//     string tmp = A.substr(i,5);
//     mp[tmp]++;
// }
// long long int mx = 0;
// for(auto it: mp){
//     long long int cnt = it.second;
//     string stmp = it.first;
//     // cout << cnt << " " << stmp << endl;
//     if(cnt > mx){
//         mx = cnt;
//         res = stmp;
//     }else if(cnt == mx){
//         if(stmp < res) res = stmp;
//     }
// }

cout << res;




return 0;
}

