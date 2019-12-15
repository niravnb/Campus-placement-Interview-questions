// H-index

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int h = 0;
        sort(citations.begin(), citations.end());
        
        for(int i = n-1; i>=0; i--){
            if(citations[i]<=h) break;
            h++;
        }
        return h;
        
    }
};



class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int h = 0;
        sort(citations.begin(), citations.end());
        
        for(int i = n-1; i>=0; i--){
            if(citations[i]>h) h++;
            else break;
        }
        return h;
        
    }
};
