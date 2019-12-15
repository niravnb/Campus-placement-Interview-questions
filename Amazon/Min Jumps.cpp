// Min Jumps

int Solution::jump(vector<int> &A) {
    int n = A.size();
    if(n<=1) return 0;
    if(A[0]==0) return -1;
    
    int maxReach = A[0], stepsLeft = A[0], jumps = 1;
    
    for(int i = 1;i<n-1;i++){
        maxReach = max(maxReach, i+A[i]);
        stepsLeft--;
        if(stepsLeft == 0){
            jumps++;
            if(i>=maxReach) return -1;
            stepsLeft = maxReach - i;
        }
    }
    
    return jumps;
}
