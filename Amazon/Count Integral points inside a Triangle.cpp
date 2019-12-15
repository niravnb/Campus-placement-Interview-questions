// Count Integral points inside a Triangle

// C++ program to find Integral points inside a triangle 
#include<bits/stdc++.h> 
using namespace std; 

// Class to represent an Integral point on XY plane. 
class Point 
{ 
public: 
	int x, y; 
	Point(int a=0, int b=0):x(a),y(b) {} 
}; 

//utility function to find GCD of two numbers 
// GCD of a and b 
int gcd(int a, int b) 
{ 
	if (b == 0) 
	return a; 
	return gcd(b, a%b); 
} 

// Finds the no. of Integral points between 
// two given points. 
int getBoundaryCount(Point p,Point q) 
{ 
	// Check if line parallel to axes 
	if (p.x==q.x) 
		return abs(p.y - q.y) - 1; 
	if (p.y == q.y) 
		return abs(p.x-q.x) - 1; 

	return gcd(abs(p.x-q.x),abs(p.y-q.y))-1; 
} 

// Returns count of points inside the triangle 
int getInternalCount(Point p, Point q, Point r) 
{ 
	// 3 extra integer points for the vertices 
	int BoundaryPoints = getBoundaryCount(p, q) + 
						getBoundaryCount(p, r) + 
						getBoundaryCount(q, r) + 3; 

	// Calculate 2*A for the triangle 
	int doubleArea = abs(p.x*(q.y - r.y) + q.x*(r.y - p.y) + 
						r.x*(p.y - q.y)); 

	// Use Pick's theorem to calculate the no. of Interior points 
	return (doubleArea - BoundaryPoints + 2)/2; 
} 

// driver function to check the program. 
int main() 
{ 
	Point p(0, 0); 
	Point q(5, 0); 
	Point r(0, 5); 
	cout << "Number of integral points inside given triangle is "
		<< getInternalCount(p, q, r); 
	return 0; 
} 
