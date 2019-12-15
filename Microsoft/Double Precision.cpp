// Double Precision

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	int orders;
	double S,x;
	S = 11.1254886467678;
// 	x=S-(int)S;
// 	double tmp = x * pow(10,7);
// 	int last = (int)tmp%10;
// 	if(last>=5){
// 	    tmp += (10-last);
// 	}
// 	tmp = tmp/(pow(10,7)) + (int)S;
	
// 	printf("%f",round(S));

    stringstream tmp;
    tmp << fixed << setprecision(6) << S;
    
    double x1 = stod(tmp.str());
    printf("%f",x1);


	return 0;
}
