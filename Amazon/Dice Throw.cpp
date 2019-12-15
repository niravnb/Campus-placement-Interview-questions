// Dice Throw


// C++ program 
// The main function that returns number of ways to get sum 'x' 
// with 'n' dice and 'm' with m faces. 
#include<bits/stdc++.h> 
using namespace std; 

long findWays(int f, int d, int s) 
{ 
	// Create a table to store results of subproblems. One extra 
	// row and column are used for simpilicity (Number of dice 
	// is directly used as row index and sum is directly used 
	// as column index). The entries in 0th row and 0th column 
	// are never used. 
	long mem[d + 1][s + 1]; 
	memset(mem,0,sizeof mem); 
	// Table entries for no dices 
	// If you do not have any data, then the value must be 0, so the result is 1 
	mem[0][0] = 1; 
	// Iterate over dices 
	for (int i = 1; i <= d; i++) 
	{ 
		// Iterate over sum 
		for (int j = i; j <= s; j++) 
		{ 
			// The result is obtained in two ways, pin the current dice and spending 1 of the value, 
			// so we have mem[i-1][j-1] remaining combinations, to find the remaining combinations we 
			// would have to pin the values ??above 1 then we use mem[i][j-1] to sum all combinations 
			// that pin the remaining j-1's. But there is a way, when "j-f-1> = 0" we would be adding 
			// extra combinations, so we remove the combinations that only pin the extrapolated dice face and 
			// subtract the extrapolated combinations. 
			mem[i][j] = mem[i][j - 1] + mem[i - 1][j - 1]; 
			if (j - f - 1 >= 0) 
				mem[i][j] -= mem[i - 1][j - f - 1]; 
		} 
	} 
	return mem[d][s]; 
} 

// Driver code 
int main(void) 
{ 
	cout << findWays(4, 2, 1) << endl; 
	cout << findWays(2, 2, 3) << endl; 
	cout << findWays(6, 3, 8) << endl; 
	cout << findWays(4, 2, 5) << endl; 
	cout << findWays(4, 3, 5) << endl; 
	return 0; 
} 

// This code is contributed by ankush_953 







// C++ program to find number of ways to get sum 'x' with 'n' 
// dice where every dice has 'm' faces 
#include <iostream> 
#include <string.h> 
using namespace std; 

// The main function that returns number of ways to get sum 'x' 
// with 'n' dice and 'm' with m faces. 
int findWays(int m, int n, int x) 
{ 
	// Create a table to store results of subproblems. One extra 
	// row and column are used for simpilicity (Number of dice 
	// is directly used as row index and sum is directly used 
	// as column index). The entries in 0th row and 0th column 
	// are never used. 
	int table[n + 1][x + 1]; 
	memset(table, 0, sizeof(table)); // Initialize all entries as 0 

	// Table entries for only one dice 
	for (int j = 1; j <= m && j <= x; j++) 
		table[1][j] = 1; 

	// Fill rest of the entries in table using recursive relation 
	// i: number of dice, j: sum 
	for (int i = 2; i <= n; i++) 
		for (int j = 1; j <= x; j++) 
			for (int k = 1; k <= m && k < j; k++) 
				table[i][j] += table[i-1][j-k]; 

	/* Uncomment these lines to see content of table 
	for (int i = 0; i <= n; i++) 
	{ 
	for (int j = 0; j <= x; j++) 
		cout << table[i][j] << " "; 
	cout << endl; 
	} */
	return table[n][x]; 
} 

// Driver program to test above functions 
int main() 
{ 
	cout << findWays(4, 2, 1) << endl; 
	cout << findWays(2, 2, 3) << endl; 
	cout << findWays(6, 3, 8) << endl; 
	cout << findWays(4, 2, 5) << endl; 
	cout << findWays(4, 3, 5) << endl; 

	return 0; 
} 
