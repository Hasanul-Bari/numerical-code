#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    int n,l;
    float x[10],a[10][10],b[10],c[10];
    cout<<endl<<"Enter the no of equations : "<<endl;
    cin>>n;
    cout<<endl<<"Enter the number of iterations : "<<endl;
    cin>>l;

    cout<<endl<<"Enter the right hand side constants : "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
    }

    cout<<endl<<"Enter the coefficients : "<<endl;
    for(int i=0;i<n;i++)
    {
        x[i]=0;
        cout<<"Equation ."<<i+1<<" : ";
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    int m=1;
    line:

    for(int i=0;i<n;i++)
    {
        c[i]=b[i];
        for(int j=0;j<n;j++)
        {
            if(i!=j)
            {
                c[i]=c[i]-a[i][j]*x[j];
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        x[i]=c[i]/a[i][i];
    }
    m++;


    if(m<=l)
    {
        goto line;
    }
    else
    {

        cout<<"\nThe Solution is : \n";

        for(int i=0;i<n;i++)
        {
            cout<<endl<<"x("<<i+1<<") = "<<x[i]<<endl;
        }
    }

}

