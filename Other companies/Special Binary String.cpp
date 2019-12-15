// Special Binary String

bool comp(string a, string b){
        return a>b;
}
class Solution {
public:
    string makeLargestSpecial(string S) {
        stack<char> s;
        vector<string> v;
        int i = 0, j = -1;
        while(i<S.length()){
            if(S[i]=='1') s.push(S[i]);
            if(S[i]=='0') s.pop();
            if(s.empty()){
                if(j+2<i-1){
                    string tmp = S.substr(j+2,i-(j+2));
                    v.push_back("1"+ makeLargestSpecial(tmp) + "0");
                }else v.push_back("10");
                j = i;
            }
            i++;
        }
        sort(v.begin(),v.end(),comp);
        string res = "";
        for(auto x: v){
            res += x;
        }
        return res;
    }
};