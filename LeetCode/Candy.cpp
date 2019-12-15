// Candy

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> dp(n,1);
        for(int i =1; i<n; i++){
            if(ratings[i] > ratings[i-1]) dp[i] = 1 + dp[i-1];
        }
        
        for(int i=n-2;i>=0; i--){
            if(ratings[i] > ratings[i+1]) dp[i] = max(dp[i], dp[i+1]+1);
        }
        
        return accumulate(dp.begin(), dp.end(),0);
    }
};



public int Candy(int[] ratings) {
            if (ratings.Length == 0) return 0;
            int ret = 1;
            int up = 0, down = 0, peak = 0;
            for (int i = 1; i < ratings.Length; i++) {
                if (ratings[i - 1] < ratings[i]) {
                    peak = ++up;
                    down = 0;
                    ret += 1 + up;
                } else if (ratings[i - 1] == ratings[i])  {
                    peak = up = down = 0;
                    ret += 1;
                } else {
                    up = 0;
                    down++;
                    ret += 1 + down + (peak >= down ? -1 : 0);
                }
            }

            return ret;
        }
