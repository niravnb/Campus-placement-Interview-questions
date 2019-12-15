// C++ program to find if a number is divisible by 
// 11 or not 
#include<bits/stdc++.h> 
using namespace std; 

// Function to find that number divisble by 11 or not 
int check(string str) 
{ 
	int n = str.length(); 

	// Compute sum of even and odd digit 
	// sums 
	int oddDigSum = 0, evenDigSum = 0; 
	for (int i=0; i<n; i++) 
	{ 
		// When i is even, position of digit is odd 
		if (i%2 == 0) 
			oddDigSum += (str[i]-'0'); 
		else
			evenDigSum += (str[i]-'0'); 
	} 

	// Check its difference is divisble by 11 or not 
	return ((oddDigSum - evenDigSum) % 11 == 0); 
} 

// Driver code 
int main() 
{ 
	string str = "76945"; 
	check(str)? cout << "Yes" : cout << "No "; 
	return 0; 
} 




// CPP implementation to find remainder 
// when a large number is divided by 11 
#include <bits/stdc++.h> 
using namespace std; 

// Function to return remainder 
int remainder(string str) 
{ 
	// len is variable to store the 
	// length of number string. 
	int len = str.length(); 

	int num, rem = 0; 

	// loop that find remainder 
	for (int i = 0; i < len; i++) { 
		num = rem * 10 + (str[i] - '0'); 
		rem = num % 11; 
	} 

	return rem; 
} 

// Driver code 
int main() 
{ 
	string str = "3435346456547566345436457867978"; 
	cout << remainder(str); 
	return 0; 
} 

