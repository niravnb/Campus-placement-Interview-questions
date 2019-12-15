class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int n = customers.size();
        int cur_sat = 0, max_sat = 0, power_sat = 0, i = 0;
        for(; i< X; i++){
            power_sat += customers[i]*grumpy[i];
            cur_sat += customers[i]*(1 - grumpy[i]);
        }
        max_sat = power_sat;
        for(; i<n; i++){
            power_sat -= customers[i-X]*grumpy[i-X];
            power_sat += customers[i]*grumpy[i];
            max_sat = max(max_sat, power_sat);
            cur_sat += customers[i]*(1 - grumpy[i]);
        }
        
        return cur_sat + max_sat;
    }
};
