// Flasks

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);



/*
 * Complete the 'chooseFlask' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY requirements
 *  2. INTEGER m
 *  3. 2D_INTEGER_ARRAY markings
 */

int chooseFlask(vector<int> requirements, int m, vector<vector<int>> markings) {
    int n = requirements.size();
    long mxreq = *max_element(requirements.begin(), requirements.end());
    vector<vector<long>> flasks;
    long notUsedFlask = 0;
    for(int i =0; i<markings.size();){
        int curr_flask = markings[i][0];

        vector<long> tmp;
        while(i<markings.size() && markings[i][0] == curr_flask){
            tmp.push_back(markings[i][1]);
            i++;
        }
        if(tmp.back() >= mxreq) flasks.push_back(tmp);
        else{
            flasks.push_back({-1});
            notUsedFlask++;
        }
        // if(tmp.size() > 0) i--;
    }

    // for(auto x: flasks){
    //     for(auto y: x) cout << y << " ";
    //     cout << endl;
    // }

    if(notUsedFlask == markings.size()) return -1;
    
    int res = 0;
    vector<long> loss;
    for(int i =0; i<flasks.size(); i++){
        if(flasks[i][0]==-1){
            loss.push_back(LLONG_MAX);
        }
        else{
            long curr_loss = 0;
            for(int j =0; j<n; j++){
                long req = requirements[j];
                long pos = upper_bound(flasks[i].begin(), flasks[i].end(), req) - flasks[i].begin();
                curr_loss += flasks[i][pos] - req;
            }
            loss.push_back(curr_loss);
        }
        
    }

    long curr_min = LLONG_MAX;
    for(int i = 0; i<loss.size(); i++){
        if(loss[i]<curr_min){
            curr_min = loss[i];
            res = i;
        }
    }
    return res;
    // return min_element(loss.begin(), loss.end()) - loss.begin();
}

int main()