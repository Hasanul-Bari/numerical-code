#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the no of equations : ";
    cin>>n;
    float a[n][n+1];

    cout<<"Coefficient of all : "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"equation: "<<i+1<< "  =  ";
        for(int j=0;j<=n;j++)
            cin>>a[i][j];
    }


    /*for(int i=n-1;i>0;i--)             // partial pivoting
    {
        if(a[i-1][0]<a[i][0])
            for(int j=0;j<=n;j++)
            {
                float c=a[i][j];
                a[i][j]=a[i-1][j];
                a[i-1][j]=c;
            }
    }*/

    /*for(int i=0;i<n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }*/


    for(int k=0;k<n-1;k++)                      //Forward elimination process//
        for(int i=k;i<n-1;i++)
        {
            float c= (a[i+1][k]/a[k][k]) ;

            for(int j=0;j<=n;j++)
                a[i+1][j]-=c*a[k][j];
        }


    cout<<endl<<"The equation in upper  triangular form : "<<endl;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=n;j++)
            printf("%6.1f",a[i][j]);
        cout<<endl;
    }

    float d[n]={0};

    for(int i=n-1;i>=0;i--)           //Backward Substitution method//
    {
        float c=0;
        for(int j=i;j<=n-1;j++)
            c=c+a[i][j]*d[j];

        d[i]=(a[i][n]-c)/a[i][i];
    }


    cout<<"The values of the variables :"<<endl;
    for(int i=0;i<n;i++)
        cout<<d[i]<<endl;

}
