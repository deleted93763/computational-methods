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

    cout << "Enter number of intervals (even): ";
    cin >> n;

    if (n <= 0 || n % 2 != 0)
    {
        cout << "Number of intervals must be positive and even.";
        return 0;
    }

    h = (b - a) / n;

    for (i = 1; i < n; i++)
    {
        x = a + i * h;

        if (i % 2 == 0)
            sum = sum + 2 * (x * x);
        else
            sum = sum + 4 * (x * x);
    }

    result = (h / 3) *
             (a * a + b * b + sum);

    cout << "Integration = " << result;

    return 0;
}