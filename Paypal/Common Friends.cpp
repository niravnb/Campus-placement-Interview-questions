// Max Pairs - Common friends - paypal

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


/*
 * Complete the 'maxShared' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts WEIGHTED_INTEGER_GRAPH friends as parameter.
 */

/*
 * For the weighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] and <name>_to[i]. The weight of the edge is <name>_weight[i].
 *
 */

int maxShared(int friends_nodes, vector<int> friends_from, vector<int> friends_to, vector<int> friends_weight) {
    int n = friends_nodes;
    int e = friends_from.size();
    unordered_map<int,int> mp;

    for(int i =0; i<e; i++){
        int u = friends_from[i];
        int v = friends_to[i];
        int interest = friends_weight[i];

        mp[max(u,v)*1000+min(u,v)]++;
    }

    int mxcount = 0, res = 0;
    for(auto it : mp){
        int pair = it.first;
        int count = it.second;
        if(count > mxcount){
            int u = pair/1000;
            int v = pair%1000;
            // cout << u << " " << v << " " << count << endl;
            res = u*v;
            mxcount = count;
        }else if(count == mxcount){
            int u = pair/1000;
            int v = pair%1000;
            // cout << u << " " << v << " " << count << endl;
            res = max(res,u*v);
        }
    }

    return res;


}
