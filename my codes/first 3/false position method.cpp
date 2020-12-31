#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

double f(double x)
{
    return (x*x*x -2*x  -5);
}

void false_position (double & x, double a, double b, double fa, double fb, int & itr)
{
    x = (a*fb -b*fa)/(fb-fa);
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

    false_position (x, a, b, f(a),f(b), itr);
    do
    {
        if (f(a)*f(x) < 0)
            b=x;
        else
            a=x;
        false_position (x1, a, b, f(a),f(b), itr);

        //cout<<abs(x1-x)<<" "<<allerror<<endl;

        if(abs(x1-x) < allerror)
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
