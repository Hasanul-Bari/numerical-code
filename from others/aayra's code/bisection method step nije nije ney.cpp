///appropriate
#include<bits/stdc++.h>
using namespace std;

//function used is x^3-2x^2+3
double func(double x)
{
    return x*x*x - 2*x - 5;
}

double e=0.001;
double c;

void bisection(double a,double b)
{
    if(func(a) * func(b) >= 0)
    {
        cout<<"Incorrect a and b";
        return;
    }

    c = a;
int i=1;
    while ((b-a) >= e)
    {
        cout<<"\nStep :"<<i<<"root=  ";
        c = (a+b)/2;
        if (func(c) == 0.0){
            cout<<c<<endl;
            break;
        }
        else if (func(c)*func(a) < 0){
                cout<<c<<endl;
                b = c;
        }
        else{
                cout<<c<<endl;
                a = c;
        }i++;
    }
}

int main()
{
    double a,b;
cout<<"Enter two roots: "<<endl;
cin>>a>>b;

    cout<<"The function used is x^3-2x^2+3\n";
  cout<<"a= "<<a<<endl;
  cout<<"b= "<<b<<endl;
    bisection(a,b);
cout<<endl;
    cout<<"Accurate Root calculated is = "<<c<<endl;

    return 0;
}
