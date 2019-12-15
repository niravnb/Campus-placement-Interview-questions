// Maximum Number of Strawberries


#include <iostream>
#include <vector>
using namespace std;

int calculateMaxStrawberries(vector<vector<int> >& memo, vector<int>& s, int pos, int left) {
  if (pos < 0 || left < 0) return 0;
  if (memo[pos][left] == -1) {
    memo[pos][left] = max(calculateMaxStrawberries(memo, s, pos - 1, left), left - s[pos] < 0 ? 0 : s[pos] + calculateMaxStrawberries(memo, s, pos - 2, left - s[pos]));
  }
  return memo[pos][left];
}

int maxStrawberries(vector<int>& s, int limit) {
  vector<vector<int> > memo(s.size(), vector<int>(limit + 1, -1));
  return calculateMaxStrawberries(memo, s, s.size() - 1, limit);
}

int main() {
  vector<int> s = {10, 20, 30, 40, 50, 900};
  cout << maxStrawberries(s, 100) << endl;
}



/////////////////////////////////////////////////////////////////
public static void main(String args[]) {
    int[] fruits = {50, 10, 20, 30, 40};
    int dp[][] = new int[5][101];
    
    for(int i = 0; i < fruits.length; ++i)
        Arrays.fill(dp[i], -1);
    
    int res = solve(fruits, fruits.length - 1, 100, dp);
    System.out.println("Result: " + (res == -1 ? 0 : res));
}

public static int solve(int fruits[], int k, int available, int dp[][]) {
    if(k < 0)
        return 0;
        
    if(dp[k][available] == -1) {
        int notSelected = solve(fruits, k - 1, available, dp);
        int selected = available - fruits[k] < 0 ? 0 : fruits[k] + solve(fruits, k - 2, available - fruits[k], dp);
        dp[k][available] = Math.max(notSelected, selected);
    }
    
    return dp[k][available];
}