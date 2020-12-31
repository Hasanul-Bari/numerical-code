#include<iostream>
#include<iomanip>
using namespace std;

double u_cal(double u, int n)
{
    double temp = u;
    for (int i = 1; i < n; i++)
        temp = temp * (u + i);
    return temp;
}

int fact(int n)
{
    int f = 1;
    for (int i = 2; i <= n; i++)
        f=f*i;
    return f;
}


int main()
{
    int n;
    cout<<"Enter the number of values to be entered : ";
    cin>>n;
    double x[n] , y[n][n];

    cout<<endl<<"Enter the values in form x,y : "<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>x[i]>>y[i][0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = n - 1; j >= i; j--)
            y[j][i] = y[j][i - 1] - y[j - 1][i - 1];
    }

    cout<<endl<<"backward diffference table"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout << setw(6) << x[i] <<"    ";
        for (int j = 0; j <= i; j++)
            cout<< setw(6)<< y[i][j]<<"     ";

        cout<<endl;
    }

    cout<<endl<<"Enter the value of x for which the value of y is wanted: ";
    double value;
    cin>>value;


    double sum = y[n - 1][0];
    double u = (value - x[n - 1]) / (x[1] - x[0]);

    for (int i = 1; i < n; i++)
    {
        sum = sum + (u_cal(u, i) * y[n - 1][i]) /fact(i);
    }

    cout <<endl<<"Value at " << value << " is "<<sum<< endl;
    return 0;

}

