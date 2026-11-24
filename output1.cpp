#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n;
    double x[20], y[20], diff[20][20];
    double value, h, u, result, term;

    cout << "Enter number of data points: ";
    cin >> n;

    cout << "Enter values of x and y:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
        diff[i][0] = y[i];
    }

    // Calculate forward difference table
    for (int j = 1; j < n; j++)
    {
        for (int i = 0; i < n - j; i++)
        {
            diff[i][j] = diff[i + 1][j - 1] - diff[i][j - 1];
        }
    }

    cout << "Enter the value of x for interpolation: ";
    cin >> value;

    // Step size
    h = x[1] - x[0];

    // u = (x - x0) / h
    u = (value - x[0]) / h;

    // Newton Forward Formula
    result = diff[0][0];
    term = 1;

    for (int i = 1; i < n; i++)
    {
        term = term * (u - (i - 1)) / i;
        result = result + term * diff[0][i];
    }

    cout << fixed << setprecision(6);
    cout << "\nInterpolated value at x = " << value
         << " is " << result << endl;

    return 0;
}