// Best Time to Buy and Sell Stock with Transaction Fee


int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int mn = prices[0], profit=0;
        for(int i =1; i<n; i++){
            if(prices[i]-mn-fee>0){
                profit += prices[i]-mn-fee;
                mn = prices[i]-fee;
            }else mn = min(mn,prices[i]);

        }
        return profit;
}


class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int hold = prices[0], profit=0;
        for(int i =1; i<n; i++){
            profit = max(profit, prices[i] - hold -fee);
            hold = min(hold, prices[i] - profit);
        }
        return profit;
    }
};
