#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'identicalPairs' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY marks as parameter.
 */

int identicalPairs(vector<int> marks) {
    int n = marks.size();
    int i =0;
    vector<int> m(marks);
    while(i+1<m.size()){
        if(m[i]==m[i+1]){
            int ms = m.size();
            m.erase(m.begin() + i,m.begin() + i + 2);
            i=0;
            if(ms == 2) break;
        }else i++;
    }

    return m.size();

}
int main()