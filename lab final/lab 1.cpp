#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

double func(double x)
{
    return ( (x*x*x*x*x)-(5*x)-1 );
}

void false_position(double & x, double a, double b,double fa,double fb, int & n)
{
    x = (a*fb -b*fa)/(fb-fa);
    n++;
    cout<<"Iteration no ."<<n<<"      x = ";
    printf("%lf\n",x);
}


int main()
{
    int i=0,n;
    double x,a,b,accuracy,x1;

    cout<<"Enter the value of a , b , accuracy and no of iterations"<<endl;
    cin>>a>>b>>accuracy>>n;

    false_position(x1,a,b,func(a),func(b),i);

    do
    {
        if (func(a)*func(x) < 0)
            b=x;
        else
            a=x;
        false_position (x1, a, b, func(a),func(b), i);

        //cout<<abs(x1-x)<<" "<<accuracy<<endl;

        if(abs(x1-x) < accuracy)
        {
            cout<<"After "<<i<<" iterations, root = "<<x1<<endl;
            return 0;
        }
        x=x1;
    }
    while (i < n);
    cout<<"The solution does not converge or iterations are not sufficient"<<endl;

    return 0;




}


