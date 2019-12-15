// Maximum Subarray Sum with One Deletion

class Solution {
public:
    int maximumSum(vector<int>& arr) {
     int n = arr.size();
     int sum_with_deletion = 0, sum_wo_deletion = arr[0], ans = arr[0];
        
    for(int i = 1; i<n; i++){
        sum_with_deletion = max(sum_wo_deletion, arr[i]+sum_with_deletion );
        
        sum_wo_deletion = max(arr[i], arr[i] + sum_wo_deletion);
        
        ans = max({ans, sum_with_deletion, sum_wo_deletion });
    }
        return ans;
    }
};
