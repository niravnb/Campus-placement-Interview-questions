// Ranking

#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'numofPrizes' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY marks
 */

int numofPrizes(int k, vector<int> marks) {
    sort(marks.begin(), marks.end(), greater<int>());
    // for(auto x: marks) cout << x << " ";
    int n = marks.size();
    int count = 0;
    if(n==0 || marks[0]==0) return 0;

    // for(int i = n-1; i>=0; i--){
    //     if(marks[i]==0) count++;
    // }

    vector<int> rank(n,-1);
    // if(count == n) return -1;
    rank[0]= 1;

    int res = n;
    int samerank = 1;
    for(int i =1; i<n; i++){
        if(marks[i]==0) return i;
        if(marks[i]==marks[i-1]){
            rank[i] = rank[i-1];
            samerank++;
        }else{
            rank[i] = rank[i-1]+samerank;
            samerank = 1;
        }
        // if(rank[i] == k) res = i;
        if(rank[i] >k) 
        {
            // if(marks[i]==0) return i-1;
            // else 
            return i;
            // break;
        }
    }
    // cout << endl;
    // for(auto x: rank) cout << x << " ";
    // res = upper_bound(rank.begin(), rank.end(), k) - rank.begin();
    return res;
    // return marks[n-1]!=0?res:-1;
}
int main()