// Top K Frequent Elements

class Solution {
public:
    
   
    struct ComparisonClass {
         bool operator()(pair<int,int> a, pair<int,int> b){
        if(a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    }
    };
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==k) return nums;
        
        unordered_map<int,int> mp;
        
        for(auto x: nums) mp[x]++;
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, ComparisonClass> pq;
        int i = 0;
        for(auto x : mp){
            if(i<k) pq.push({x.second, x.first});
            else{
                auto tmp = pq.top();
                if(tmp.first < x.second){
                    pq.pop();
                    pq.push({x.second, x.first});
                }
            }
            i++;
        }
        vector<int> res(k);
        while(!pq.empty()){
            res[--k] = pq.top().second;
            pq.pop();
        }
        
        
        return res;
    }
};
