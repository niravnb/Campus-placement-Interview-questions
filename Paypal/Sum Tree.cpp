// Binary Sum Tree Paypal
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'bestSumAnyTreePath' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY parent
 *  2. INTEGER_ARRAY values
 */

    long ans = LLONG_MIN;
    vector<long> dp;

 long solve(int curr, int par, vector<vector<int>> &adj, vector<int> &values){

     if(dp[curr] != LLONG_MIN) return dp[curr];

     long val = values[curr];

    vector<long> adj_sums;
    // int mx_childs = INT_MIN+1005;
    for(auto it: adj[curr]){
         if(it == par) continue;
         long adj_sum = solve(it, curr, adj, values);
         adj_sums.push_back(adj_sum);
        //  mx_childs = max(mx_childs, adj_sum);
    }
    //   = *max_element(adj_sums.begin(), adj_sums.end());
    //  int ret = max(val, max(val+mx_childs, mx_childs));
    // adj_sums.push_back(val);
    sort(adj_sums.begin(), adj_sums.end());

    // for(auto x: adj_sums) cout << x << " ";
    // cout << endl;
    long ret;
    if(adj_sums.size() == 0){
        ret = val;
    }else if(adj_sums.size() == 1){
        ret = max(val, val+adj_sums[0]);
    }else{
        long l = adj_sums.back(), l1 = adj_sums[adj_sums.size()-2];
        vector<long> potential = {val, val+l+l1, val + l};
        // ret = max(val, max(val + l + l1, max(l, max(l1, val + l ))));
        ret = *max_element(potential.begin(), potential.end());
    }



    // long ret;
    // if(adj_sums.size() == 0){
    //     ret = val;
    // }else if(adj_sums.size() == 1){
    //     ret = max(val, max(val+adj_sums[0], adj_sums[0]));
    // }else{
    //     long l = adj_sums.back(), l1 = adj_sums[adj_sums.size()-2];
    //     vector<long> potential = {val, val+l+l1, l, val + l};
    //     // ret = max(val, max(val + l + l1, max(l, max(l1, val + l ))));
    //     ret = *max_element(potential.begin(), potential.end());
    // }


    ans = max(ans,ret);
    return dp[curr]=ret;
    
    
    //  cout << ret << " " << val << " " << mx_childs  <<endl; 
    //  return ret;
    // return val;



    // if(adj_sums.size() == 1){
    //     cout << adj_sums[0] << endl;
    //     return adj_sums[0];
    // }else{
    //     long l = adj_sums.back(), l1 = adj_sums[adj_sums.size()-2];
    //     int ret = max(l+l1, l);
    //     cout << ret << endl;
    //     return ret;
    // }
 }

int bestSumAnyTreePath(vector<int> parent, vector<int> values) {
    int n = parent.size();
    vector<vector<int>> adj(n);

    dp.resize(n, LLONG_MIN);

    for(int i =0; i<n; i++){
        if(parent[i]==-1)continue;
        int par = parent[i];
        adj[par].push_back(i);
        adj[i].push_back(par);
    }

    // for(auto x: adj){
    //     for(auto y:x) cout << y << " ";
    //     cout << endl;
    // }

    // long res = solve(0, -1, adj, values);
    long final_ans = LLONG_MIN;
    for(int i =0; i<n; i++){
        long res = solve(i, parent[i], adj, values);
        final_ans = max(final_ans, res);
    }

    return final_ans;
    // return res;
    // long mx = *max_element(values.begin(), values.end());
    // return max(mx, res);
    // return max(ans, mx);

}

int main()