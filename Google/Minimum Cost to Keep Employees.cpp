// Minimum Cost to Keep Employees

// Constraints were:
// 1 <= noOfMonths <= 10000; 0 < employeesRequired < 50; 0 < Hiring Cost, Salary, Severance Pay <= 10^9
// TC: O(n * max(emps))
// SC: O(n * max(emps))

int solve(int prev, int hire, int salary, int severance, int idx,
	     vector<int> &emps, vector<vector<int > > &dp) {
    if (dp[idx][prev] == -1) {
        if (idx == emps.size()) {
            dp[idx][prev] = 0;
        } else {
            int cost = 0;
            if (emps[idx] >= prev) {
                // hire everyone
                // hiring cost + cur month salary
                cost += (emps[idx] - prev) * hire + emps[idx] * salary + solve(
                	emps[idx], hire, salary, severance, idx + 1, emps, dp
                );
            } else {
                int cur = INT_MAX;
                // try all possible combinations
                for (int i = emps[idx]; i <= prev; i++) {
                    // hire i emp
                    // severance cost + cur month salary
                    int curCost = (prev - i) * severance + i * salary + solve(
                    	i, hire, salary, severance, idx + 1, emps, dp
                    );
                    cur = min(cur, curCost);
                }
                cost += cur;
            }
            dp[idx][prev] = cost;
        }
    }
    return dp[idx][prev];
}


int minCTC(int hire, int salary, int severance, vector<int> emps) {
    int n = emps.size();
    vector<vector <int> > dp(n + 1, vector<int> (51, -1));
    int ans = solve(0, hire, salary, severance, 0, emps, dp);
    return ans;
}


int main() {
    vector<int> emps = {14, 10, 11};
	assert(minCTC(5, 6, 7, emps) == 307);
	return 0;
}







////////////////////////////////////////////////////////////////////////

def solver(cost,salary,severance,nums):
    dp = {0:0}
    for req in nums:
        tmp = collections.defaultdict(lambda: float('inf'))
        for key in dp:
            if key >= req:
                for i in range(req,key+1):
                    tmp[i] = min(tmp[i],dp[key]+i*salary+(key-i)*severance)
            else:  tmp[req] = min(tmp[req],dp[key]+req*salary+(req-key)*cost)
        dp = tmp
    return min(dp.values())













///////////////////////////////////////////////////////////////////////

int calculateHiringCost(int hiringCost, int salary, int severanceFee, int months, vector<int>& employees)
{
	if (months == 0 || employees.size() == 0)
		return 0;
	int currentEmployees = 0;
	int currentHiringCost = 0;
	int minHiringCost = INT_MAX;
	for (int i = 0; i < months; i++)
	{
		if (currentEmployees < employees[i])
		{
			int newEmployees = employees[i] - currentEmployees;
			currentHiringCost = newEmployees * (hiringCost + salary);
			currentHiringCost += currentEmployees * salary;
			currentEmployees += newEmployees;
		}
		else if (currentEmployees > employees[i])
		{
			if (employees[i] == 0)
			{
				currentEmployees = 0;
				continue;
			}
			int firedEmployees = currentEmployees - employees[i];
			int fees = firedEmployees * severanceFee;
			currentEmployees = currentEmployees - employees[i];
			currentHiringCost = currentEmployees * salary +  fees;
		}
		else {
			currentHiringCost = currentEmployees * salary;
		}
		minHiringCost = min(currentHiringCost, minHiringCost);
	}
	return minHiringCost;
}
