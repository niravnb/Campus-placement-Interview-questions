// Sum of digits

#include <stdio.h>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;

typedef long  llint;

llint A, B;
llint powTen[19];
llint memo[19][200];
llint min_solution = -1;
llint rec( llint prefix, llint digits, llint sum ) {
   if( sum < 0 ) return 0;
   llint mini = prefix;
   llint maxi = prefix + powTen[digits];
   if( mini > B || maxi < A ) return 0;
   if( digits == 0 ) {
      if( sum > 0 ) return 0;      
      if( min_solution == -1 ) min_solution = prefix;
      return 1;
   }
   int memoize = (mini >= A && maxi <= B);
   if( memoize && memo[digits][sum] != -1 ) return memo[digits][sum];
   llint ret = 0;
   
   for( int dig = 0; dig < 10; ++dig ) 
      ret += rec( prefix + dig*powTen[digits-1], digits-1, sum-dig );   
   if( memoize ) memo[digits][sum] = ret;
   return ret;
}
int main( void ) 
{
   powTen[0] = 1;
   for( int i = 1; i <= 19; ++i ) powTen[i] = powTen[i-1] * 10;
   
   llint S;
   cin >> A >> B >> S;
   
   memset( memo, -1, sizeof memo );
   cout << rec( 0, 19, S ) << endl;
   cout << min_solution << endl;
   
 
   return 0;
}