#include <iostream>
#include <cmath>
using namespace std;

// Function f(x)
double f(double x)
{
    return x*x*x - x - 2;
}

// Derivative f'(x)
double df(double x)
{
    return 3*x*x - 1;
}

int main()
{
    double x, x1;
    int n, i;

    cout << "Enter initial guess: ";
    cin >> x;

    cout << "Enter number of iterations: ";
    cin >> n;

    cout << "\nIteration\t x\t\t f(x)\n";

    for(i = 1; i <= n; i++)
    {
        // Newton-Raphson formula
        x1 = x - f(x) / df(x);

        cout << i << "\t\t" << x1 << "\t\t" << f(x1) << endl;

        x = x1;
    }

    cout << "\nApproximate root = " << x << endl;

    return 0;
}