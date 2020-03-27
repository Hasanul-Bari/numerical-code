#include<iostream>
#include<iomanip>
using namespace std;

double p_cal(double p, int n)
{
    double temp = p;
    for (int i = 1; i < n; i++)
        temp = temp * (p - i);
    return temp;
}

int fact(int n)
{
    int f = 1;
    for (int i = 2; i <= n; i++)
        f =f*i;

    return f;
}


int main()
{
    int n;
    cout<<"Enter the number of values to be entered : ";
    cin>>n;
    double x[n], y[n][n];

    cout<<endl<<"Enter the values in form x,y : "<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>x[i]>>y[i][0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            y[j][i] = y[j + 1][i - 1] - y[j][i - 1];

        }
    }


    cout<<endl<<"Forward diffference table"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout << setw(6) << x[i] <<"    ";
        for (int j = 0; j < n - i; j++)
            cout<< setw(6)<< y[i][j]<<"     ";

        cout << endl;
    }

    cout<<endl<<"Enter the value of x for which the value of y is wanted: ";
    double value;
    while(cin>>value)
    {


        double sum = y[0][0];
        double p = (value - x[0]) / (x[1] - x[0]);
        //cout<<x[1]-x[0]<<endl;
        //cout<<"p= "<<p<<endl;
        for (int i = 1; i < n; i++)
        {
            sum = sum + (p_cal(p, i) * y[0][i]) /fact(i);
        }

        cout <<endl<<"Value at " << value << " is "<<sum<< endl;

        cout<<endl<<"Enter the value of x for which the value of y is wanted: ";


    }
    return 0;
}

/*
0 0
2 4
4 56
6 204
8 496
10 980
*/
