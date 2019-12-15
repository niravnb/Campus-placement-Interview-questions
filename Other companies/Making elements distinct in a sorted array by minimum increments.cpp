// Making elements distinct in a sorted array by minimum increments

// Efficient CPP program to make sorted array 
// elements distinct by incrementing elements 
// and keeping sum to minimum. 
#include <iostream> 
using namespace std; 

// To find minimum sum of unique elements. 
int minSum(int arr[], int n) 
{ 
   int sum = arr[0], prev = arr[0]; 

   for (int i = 1; i < n; i++) { 

      // If violation happens, make current 
      // value as 1 plus previous value and 
      // add to sum. 
      if (arr[i] <= prev) { 
         prev = prev + 1; 
         sum = sum + prev; 
      } 

      // No violation. 
      else { 
         sum = sum + arr[i]; 
         prev = arr[i]; 
      } 
   } 

   return sum; 
} 

// Drivers code 
int main() 
{ 
   int arr[] = { 2, 2, 3, 5, 6 }; 
   int n = sizeof(arr) / sizeof(arr[0]); 
   cout << minSum(arr, n) << endl; 
   return 0; 
} 



// CPP program to make sorted array elements 
// distinct by incrementing elements and keeping 
// sum to minimum. 
#include <iostream> 
using namespace std; 

// To find minimum sum of unique elements. 
int minSum(int arr[], int n) 
{ 
   int sum = arr[0]; 

   for (int i = 1; i < n; i++) { 
      if (arr[i] == arr[i - 1]) {          

         // While current element is same as 
         // previous or has become smaller 
         // than previous. 
         int j = i; 
         while (j < n && arr[j] <= arr[j - 1]) {       
            arr[j] = arr[j] + 1; 
            j++; 
         } 
      } 
      sum = sum + arr[i]; 
   } 

   return sum; 
} 

// Driver code 
int main() 
{ 
   int arr[] = { 2, 2, 3, 5, 6 }; 
   int n = sizeof(arr) / sizeof(arr[0]); 
   cout << minSum(arr, n) << endl; 
   return 0; 
} 
