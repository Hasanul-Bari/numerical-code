#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int n;
    float a[20][20],x[10];
    cout<<"Enter the no of equations : ";
    cin>>n;


    cout<<"Coefficient of all : "<<endl;
    for(int i=1; i<=n; i++)
    {
        cout<<"equation: "<<i<< "  =  ";
        for(int j=1; j<=(n+1); j++)
        {
            cin>>a[i][j];
        }
    }
    /* Now finding the elements of diagonal matrix */
    for(int j=1; j<=n; j++)
    {
        for(int i=1; i<=n; i++)
        {
            if(i!=j)
            {
                float c=a[i][j]/a[j][j];
                for(int k=1; k<=n+1; k++)
                {
                    a[i][k]=a[i][k]-c*a[j][k];
                }
            }
        }
    }

    cout<<endl<<"The solution is: "<<endl;
    for(int i=1; i<=n; i++)
    {
        x[i]=a[i][n+1]/a[i][i];
        printf("\n x%d=%6.1f\n",i,x[i]);
    }
    return 0;
}
