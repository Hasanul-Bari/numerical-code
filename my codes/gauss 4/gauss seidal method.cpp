#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
    cout.precision(4);
    cout.setf(ios::fixed);
    int n,i,j,k,flag=0,count=0;
    cout<<"Enter the no. of equations\n";
    cin>>n;
    double a[n][n+1];
    double x[n]={0};
    double eps,y;

    cout<<"\nEnter the elements of the augmented matrix row-wise:\n";
    for (i=0; i<n; i++)
        for (j=0; j<=n; j++)
            cin>>a[i][j];

    /*cout<<"\nEnter the initial values of the variables:\n";
    for (i=0; i<n; i++)
        cin>>x[i];*/


    cout<<"\nEnter the accuracy upto which you want the solution:\n";
    cin>>eps;
    for (i=0; i<n; i++)
        for (k=i+1; k<n; k++)
            if (abs(a[i][i])<abs(a[k][i]))
                for (j=0; j<=n; j++)
                {
                    double temp=a[i][j];
                    a[i][j]=a[k][j];
                    a[k][j]=temp;
                }

    cout<<"Iter"<<setw(10);
    for(i=0; i<n; i++)
        cout<<"x"<<i<<setw(18);


    do
    {
        cout<<"\n"<<count+1<<"."<<setw(16);
        for (i=0; i<n; i++)
        {
            y=x[i];
            x[i]=a[i][n];
            for (j=0; j<n; j++)
            {
                if (j!=i)
                    x[i]=x[i]-a[i][j]*x[j];
            }
            x[i]=x[i]/a[i][i];
            if (abs(x[i]-y)<=eps)
                flag++;
            cout<<x[i]<<setw(18);
        }
        cout<<"\n";
        count++;
    }
    while(flag<n);
    cout<<"\n The solution is as follows:\n";
    for (i=0; i<n; i++)
        cout<<"x"<<i<<" = "<<x[i]<<endl;        //Print the contents of x[]
    return 0;
}

/*
5 -2 3 -1
-3 9 1 2
2 -1 -7 3

*/

/*
1 2 3 10
6 5 2 30
3 9 1 25

*/

/*
10 2 1 9
2 20 -2 -44
-2 3 10 22
*/