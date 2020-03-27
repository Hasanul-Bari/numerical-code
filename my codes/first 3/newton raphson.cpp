#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

double f(double x)
{
    return (2*x*x*x*x*x -5*x  -1);
}

double df(double x)
{
    return (10*x*x*x*x -5);
}


int main()
{
    int itr, maxitr;
    double x0, x, allerror, h;
    cout<<"Enter the values of x0, allowed error and maximum no of iterations: "<<endl;
    cin>>x0>>allerror>>maxitr;


    for (itr=1; itr<=maxitr; itr++)
    {
        h=f(x0)/df(x0);
        x=x0-h;
        cout<<"Iteration no ."<<itr<<"      x = ";
        printf("%lf\n",x);

        if (fabs(h) < allerror)
        {
            cout<<"After "<<itr<<" iterations, root = "<<x<<endl;
            return 0;
        }
        x0=x;
    }
    cout<<"The solution does not converge or iterations are not sufficient"<<endl;
    return 1;
}
