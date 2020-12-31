#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

double f(double x)
{
    return (x*x*x -2.0*x  -5.0);
}

void bisection(double & x,double a,double b,int & itr)
{
    x=(a+b)/2;
    itr++;
    cout<<"Iteration no ."<<itr<<"      x = ";
    printf("%lf\n",x);
}


int main()
{
    int itr = 0, maxitr;
    double x, a, b, allerror, x1;
    cout<<"Enter the values of a, b, allowed error and maximum no of iterations: "<<endl;
    cin>>a>>b>>allerror>>maxitr;

    bisection (x, a, b, itr);
    do
    {
        if (f(a)*f(x) < 0)
            b=x;
        else
            a=x;
        bisection (x1, a, b, itr);
        if (abs(x1-x) < allerror)
        {
            cout<<"After "<<itr<<" iterations, root = "<<x1<<endl;
            return 0;
        }
        x=x1;
    }
    while (itr < maxitr);
    cout<<"The solution does not converge or iterations are not sufficient"<<endl;
    return 1;
}
