#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the number of equations"<<endl;
    cin>>n;
    double a[n+1][n+1],b[n+1];

    cout<<"Enter the equations"<<endl;
    for(int i=1; i<=n; i++)
    {
        cout<<"Eqution "<<i<<" : ";
        for(int j=1; j<=n; j++)
        {
            cin>>a[i][j];
        }
        cin>>b[i];
    }

    double x[n+1]= {0};

    /*cout<<"Enter the number of iterations"<<endl;
    int itr;
    cin>>itr;*/

    ///pivoting


    for (int i=1; i<=n; i++)
    {
        for (int k=i+1; k<=n; k++)
        {
            if (abs(a[i][i])<abs(a[k][i]))
            {
                double temp;
                for (int j=1; j<=n; j++)
                {
                    temp=a[i][j];
                    a[i][j]=a[k][j];
                    a[k][j]=temp;
                }
                temp=b[i];
                b[i]=b[k];
                b[k]=temp;

            }
        }
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<b[i]<<endl;
    }




    double tmp[n+1]={0};

    double eps;

    cout<<"\nEnter the accuracy upto which you want the solution:\n";
    cin>>eps;

    int flag=0;
    do
    //for(int i=1; i<=itr; i++)
    {
        for(int j=1; j<=n; j++)
        {
            tmp[j]=b[j];
            //cout<<x[j]<<" * ";
            for(int k=1; k<=n; k++)
            {
                if(k!=j)
                {
                    //cout<<"( "<<a[j][k]<<" "<<x[k]<<" ) ";
                    tmp[j]=tmp[j]-(a[j][k]*x[k] );
                }
            }
            tmp[j]=tmp[j]/a[j][j];
            printf("%lf   ",tmp[j]);
            if( abs(tmp[j]-x[j]) <=eps )
                flag++;
        }
        cout<<endl;


        for(int j=1; j<=n; j++)
            x[j]=tmp[j];
    }
    while(flag<n);




    cout<<"\n\nThe solution is : \n";
    for(int i=1; i<=n; i++)
    {
        cout<<"x"<<i<<" = "<<x[i]<<endl;
    }

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
