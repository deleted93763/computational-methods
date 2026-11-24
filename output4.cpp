#include <iostream>
using namespace std;

int main()
{
    int n;
    float x[20], y[20], xp, yp = 0, term;

    cout << "Enter the number of data points: ";
    cin >> n;

    cout << "Enter the values of x and y:" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "x[" << i << "] = ";
        cin >> x[i];

        cout << "y[" << i << "] = ";
        cin >> y[i];
    }

    cout << "Enter the value of x for interpolation: ";
    cin >> xp;

    // Lagrange Interpolation Formula
    for (int i = 0; i < n; i++)
    {
        term = y[i];

        for (int j = 0; j < n; j++)
        {
            if (j != i)
            {
                term = term * (xp - x[j]) / (x[i] - x[j]);
            }
        }

        yp = yp + term;
    }

    cout << "\nInterpolated value at x = " << xp
         << " is y = " << yp << endl;

    return 0;
}