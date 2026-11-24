#include <iostream>
#include <cmath>
using namespace std;

// Function
float f(float x)
{
    return x*x*x - x - 2;
}

int main()
{
    float a, b, c;
    int n;

    cout << "Enter lower limit a: ";
    cin >> a;

    cout << "Enter upper limit b: ";
    cin >> b;

    cout << "Enter number of iterations: ";
    cin >> n;

    // Check whether root exists
    if (f(a) * f(b) >= 0)
    {
        cout << "Bisection method cannot be applied.";
        return 0;
    }

    cout << "\nIteration\t a\t\t b\t\t c\t\t f(c)\n";

    for (int i = 1; i <= n; i++)
    {
        // Calculate midpoint
        c = (a + b) / 2;

        cout << i << "\t\t"
             << a << "\t"
             << b << "\t"
             << c << "\t"
             << f(c) << endl;

        // Check which interval contains the root
        if (f(a) * f(c) < 0)
        {
            b = c;
        }
        else
        {
            a = c;
        }
    }

    cout << "\nApproximate root = " << c << endl;

    return 0;
}