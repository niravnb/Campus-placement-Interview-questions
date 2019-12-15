 // Largest Component Size by Common Factor

class Solution {
public:
    int find(int a, vector<int> &par){
        if(par[a]!=a){
            par[a] = find(par[a], par);
        }
        return par[a];
    }

    void un(int a, int b, vector<int> &par, vector<int> &rank){
        int x = find(a, par);
        int y = find(b, par);
        if(x == y ) return;
        if(rank[x] >= rank[y]){
            par[y] = x;
            rank[x] += rank[y];
        }else{
            par[x] = y;
            rank[y] += rank[x];
        }
    }
    
    int largestComponentSize(vector<int>& A) {
        int n = A.size();
        
        vector<int> par(n,0);
        vector<int> rank(n,1);
        for(int i =0; i<n; i++) par[i] = i;
        
        unordered_map<int, vector<int>> mp;
        
        for(int i =0; i<n; i++){
            int x = A[i];            
            for(int j = 2; j*j<=x; j++){
                bool tmp = false;
                while(x%j==0){
                    x = x/j;
                    tmp = true;
                }
                if(tmp) mp[j].push_back(i);
            }
            if(x>=2) mp[x].push_back(i);
        }
        
        for(auto it: mp){
            auto vec = it.second;
            for(int i = 0; i<vec.size()-1; i++){
                un(vec[i],vec[i+1],par,rank);
            }           
        }
        
                
        return *max_element(rank.begin(), rank.end());
        
    }
};
