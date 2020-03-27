 ///vul
     #include <cstdlib>
     #include <iostream>
     #include <conio.h>
     #include <math.h>

using namespace std; // DEV software code for using 'cin' instead 'scanf'
int main()
{
    int n,i,j,l=0;
    cout<<"Enter number of Equations = ";
    cin>>n;
    double a[n-1][n-1],b[n-1][1],x[n-1][1],T[n-1][1],e,k;
    cout<<"[a].[x]=[b]"<<endl;
    cout<<"Enter Matrix a:"<<endl;
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    {
        cout<<"a["<<i<<","<<j<<"] = ";
        cin>>a[i][j];
    }
    cout<<"Enter Matrix b:"<<endl;
    for(j=0;j<n;j++)
    {
        cout<<"b[0,"<<j<<"] = ";
        cin>>b[0][j];
    }
    cout<<"Enter the Accuracy = ";
    cin>>e;
    for (i=0;i<n;i++)
        T[i][0]=0;
    while (l!=n)
    {
        l=0;
        for (i=0;i<n;i++)
        {
            x[i][0]=(1/a[i][i])*(b[i][0]);
            for (j=0;j<n;j++)
            {
                if (j!=i)
                x[i][0]=x[i][0]-(1/a[i][i])*(a[i][j]*T[j][0]);
            }
        }
        for(i=0;i<n;i++)
        {
            k=fabs(x[i][0]-T[i][0]);
            if (k<=e)
            {
                l=l+1;
            }
        }
    for (i=0;i<n;i++)
        T[i][0]=x[i][0];
    }
    for (i=0;i<n;i++)
        cout<<"x"<<i+1<<"="<<x[i][0]<<endl;
    getch();
    return 0;
}
