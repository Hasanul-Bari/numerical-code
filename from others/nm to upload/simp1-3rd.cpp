// CPP program for simpson's 1/3 rule
#include <iostream>
#include <math.h>
#define PI 3.14159
using namespace std;

// Function to calculate f(x)
float func(float x)
{
	//return log(x);
	//return 1/4.0*(x*x*x);
	return sin(x)/(1+(x*x));
}

// Function for approximate integral
float simpsons_(float ll, float ul, int n)
{
	// Calculating the value of h
	float h = (ul - ll) / n;

	// Array for storing value of x and f(x)
	float x[10], fx[10];

	// Calculating values of x and f(x)
	for (int i = 0; i <= n; i++) {
		x[i] = ll + i * h;
		fx[i] = func(x[i]);
	}

	// Calculating result
	float res = 0;
	for (int i = 0; i <= n; i++) {
		if (i == 0 || i == n)
			res += fx[i];
		else if (i % 2 != 0)
			res += 4 * fx[i];
		else
			res += 2 * fx[i];
	}
	res = res * (h / 3);
	return res;
}

// Driver program
int main()
{
	float lower_limit, upper_limit,a,b;
	cout<<"Enter Upper Limit: ";
	cin>>a;
    //upper_limit= a*(PI/180);
    cout<<"Enter Lower Limit: ";
    cin>>b;
    //lower_limit= b*(PI/180);
    cout<<"Enter the number of intervals: ";
	int n;
	cin>>n;
	cout << simpsons_(b, a, n);
	return 0;
}

