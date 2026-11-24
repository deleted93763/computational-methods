#include <iostream>
#include <cmath>
using namespace std;

// Function f(x)
double f(double x)
{
    return x * x * x - x - 1;
}

int main()
{
    double x0, x1, x2;
    double f0, f1;
    double tolerance;
    int maxIter, i;

    cout << "Enter first initial guess x0: ";
    cin >> x0;

    cout << "Enter second initial guess x1: ";
    cin >> x1;

    cout << "Enter tolerance: ";
    cin >> tolerance;

    cout << "Enter maximum number of iterations: ";
    cin >> maxIter;

    cout << "\nIteration\t x0\t\t x1\t\t x2\n";

    for (i = 1; i <= maxIter; i++)
    {
        f0 = f(x0);
        f1 = f(x1);

        // Secant formula
        x2 = x1 - (f1 * (x1 - x0)) / (f1 - f0);

        cout << i << "\t\t"
             << x0 << "\t\t"
             << x1 << "\t\t"
             << x2 << endl;

        // Check convergence
        if (fabs(x2 - x1) < tolerance)
        {
            cout << "\nRoot = " << x2 << endl;
            cout << "Number of iterations = " << i << endl;
            break;
        }

        // Update values
        x0 = x1;
        x1 = x2;
    }

    if (i > maxIter)
    {
        cout << "\nRoot did not converge within "
             << maxIter << " iterations." << endl;
    }

    return 0;
}
