#include<iostream>

using namespace std;

int main()
{
    int n;
    cout<<"Enter the number of values to be entered : ";
    cin>>n;
    double x[n] , y[n];

    cout<<endl<<"Enter the values in form x,y : "<<endl;

    for(int i=0; i<n; i++)
    {
        cin>>x[i]>>y[i];
    }

    double s1=0,s2=0,x_,y_;
    for(int i=0; i<n; i++)
    {
        s1=s1+x[i];
        s2=s2+y[i];
    }

    x_=s1/n;
    y_=s2/n;

    double w1,w0;

    s1=0, s2=0;
    for(int i=0; i<n; i++)
    {
        s1=s1+((x[i]-x_)*(y[i]-y_));
        s2=s2+((x[i]-x_)*(x[i]-x_));
    }

    w1=s1/s2;

    w0=y_-(w1*x_);

    double a;
    cout<<endl<<"Enter the value of x for which the value of y is wanted: ";
    cin>>a;

    double b=w0+(w1*a);

    cout<<endl<<"Value at "<<a<<" is "<<b<<endl;

}
