#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n, i;
    float a, b, h, x, sum = 0, result;

    cout << "Enter lower limit: ";
    cin >> a;

    cout << "Enter upper limit: ";
    cin >> b;

    cout << "Enter number of intervals (multiple of 3): ";
    cin >> n;

    if (n <= 0 || n % 3 != 0)
    {
        cout << "Number of intervals must be a positive multiple of 3.";
        return 0;
    }

    h = (b - a) / n;

    for (i = 1; i < n; i++)
    {
        x = a + i * h;

        if (i % 3 == 0)
            sum = sum + 2 * (x * x);
        else
            sum = sum + 3 * (x * x);
    }

    result = (3 * h / 8) *
             (a * a + b * b + sum);

    cout << "Integration = " << result;

    return 0;
}