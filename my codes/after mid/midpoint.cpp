#include<iostream>
#include<cmath>

using namespace std;

double func(double x)
{
   // x=x*(3.142/180.0);
    return 1.0/(1.0+pow(x,5));
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
    p[0]=a;
    for(int i=1; i<=size; i++)
    {
        p[i]=p[i-1]+h;
    }

    double midp [size];
    double ans=0;
    for(int i=0; i<size; i++)
    {
        midp[i]=(p[i]+p[i+1])/2.0;
        //cout<<midp[i]<<" ";
        //cout<<func(midp[i])<<" ";
        //cout<<endl;
        ans=ans+func(midp[i]);
    }

    cout<<ans*h<<endl;



}
