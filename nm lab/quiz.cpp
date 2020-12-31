#include<iostream>
#include<cmath>
using namespace std;

double f (double x)
{
    return (2*x*x*x*x*x -5*x  -1);
}

double df(double x)
{
    return (10*x*x*x*x -5);
}


int main()
{
    int it, maxitr;
    double x0, x, allerror, h;
    cout<<endl<<"Enter x0, allowed error and no of iterations: "<<endl;
    cin>>x0>>allerror>>maxitr;


    for (it=1; it<=maxitr; it++)
    {
        h=f(x0)/df(x0);
        x=x0-h;
        cout<<"Iteration no ."<<it<<"      x = "<<x<<endl;

        if (fabs(h) < allerror)
        {
            cout<<"After "<<it<<" iterations, root = "<<x<<endl;
            return 0;
        }
        x0=x;
    }
    cout<<"iterations are not sufficient"<<endl;
    return 1;
}
