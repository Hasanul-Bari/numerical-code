#include<iostream>
#include<cmath>

using namespace std;

double func(double x)
{
    // x=x*(3.142/180.0);
    return sin(x);
}


int main()
{

    double a,b,h,n;
    cout<<"Enter the lower limit : "<<endl;
    cin>>a;
    cout<<"Enter the upper limit : "<<endl;
    cin>>b;

    cout<<"Enter the number of intervals"<<endl;
    cin>>n;

    h=(b-a)/n;
    //cout<<h<<endl;

    int size=int(n);

    double p[size+1];
    double ans=0;
    p[0]=a;
    ans=ans+func(p[0]);
    for(int i=1; i<size; i++)
    {
        p[i]=p[i-1]+h;
        if(i%2==0)
            ans=ans+(2.0*func(p[i]));
        else
            ans=ans+(4.0*func(p[i]));

    }
    p[size]=b;
    ans=ans+func(p[size]);


    cout<<ans*h/3.0<<endl;



}


