#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
double f(double x)
{
    double m = pow(x,3) - 2 * x - 5.0;
    return m;
}

double fprime(double x)
{
    double m = 3 * pow(x,2) - 1;
    return m;
}

int main()
{
    cout << setprecision(6) << fixed;
    double x,x1,e,fx,fx1;
    cout << "Enter initial guesses :";
    cin >> x1;
    cout<< "Enter desired accuracy : ";
    cin >> e;
    do
    {
      static int i =1;
      x = x1;
      fx = f(x);
      fx1 = fprime(x);
      x1 = x - (fx/fx1);
      cout << "step - " << i << "       " << "x = " << x << "       " <<"f(x) = " << fx << "        " <<"fprime(x) =  " << fx1 << "        "  << "X(n+1) = " << x1 << endl;
      i++;
    }

    while ((fabs( x1 - x)) >= e);


    cout << "the root of the equation is = " << x1;

    return 0;

}

