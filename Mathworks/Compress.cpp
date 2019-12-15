#include <bits/stdc++.h>

using namespace std;


/*
 * Complete the 'betterCompression' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */
int convert(string s){
    int res = 0;
    for(int i =0; i<s.length(); i++){
        res = res*10 + s[i]-'0';
    }
    return res;
}

string betterCompression(string s) {
    string res = "";
    map<char, int> mp;
    for(int i =0; i<s.length();){
        char a = s[i];
        string tmp;
        i++;
        while(s[i] >= '0' && s[i] <='9'  ){
            tmp+=s[i++];
        }
        int x = convert(tmp);
        mp[a]+=x;
    }

    for(auto x: mp){
        // cout << x.first << " " << x.second << endl;;
        res+=x.first+to_string(x.second);
    }
    return res;

}

int main()