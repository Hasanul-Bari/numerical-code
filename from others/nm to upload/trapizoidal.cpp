// C++ program to implement Trapezoidal rule
#include<iostream>
#include<math.h>
#define PI 3.14159
using namespace std;
// A sample function whose definite integral's
// approximate value is computed using Trapezoidal
// rule
float y(float x)
{
	// Declaring the function f(x) = 1/(1+x*x)
	//return 1/(1+x*x);
	return sin(x);
}

// Function to evalute the value of integral
float trapezoidal(float a, float b, float n)
{
	// Grid spacing
	float h = (b-a)/n;

	// Computing sum of first and last terms
	// in above formula
	float s = y(a)+y(b);

	// Adding middle terms in above formula
	for (int i = 1; i < n; i++)
		s += 2*y(a+i*h);

	// h/2 indicates (b-a)/2n. Multiplying h/2
	// with s.
	return (h/2)*s;
}

// Driver program to test above function
int main()
{
	float lower_limit, upper_limit,a,b;
	cout<<"Enter Upper Limit: ";
	cin>>a;
    upper_limit= a*(PI/180);
    cout<<"Enter Lower Limit: ";
    cin>>b;
    lower_limit= b*(PI/180);
    cout<<"Enter the number of intervals: ";
	int n;
	cin>>n;
	cout << trapezoidal(lower_limit, upper_limit, n);
	return 0;
}

