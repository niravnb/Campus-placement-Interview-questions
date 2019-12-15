#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'arrangeEquipments' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY equipments as parameter.
 */

vector<int> arrangeEquipments(vector<int> equipments) {
    int n = equipments.size();
    vector<int> res(n,-1), arr(equipments);
    sort(arr.begin(), arr.end());

    int j = 0;
    for(int i =1; i<n; i++){
        int ind = i+1;
        if(ind%2){
            res[i] = arr[j++]; 
        }
    }

    for(int i =0; i<n; i++){
        if(res[i]==-1){
            res[i] = arr[j++];
        }
    }
    return res;

}

int main()