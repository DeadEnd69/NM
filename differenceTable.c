#include <stdio.h>

double divided_difference(double x[], double f[], int n, int start, int end)
{
    if (start == end)
    {
        return f[start];
    }
    else
    {
        return (divided_difference(x, f, n, start + 1, end) - divided_difference(x, f, n, start, end - 1)) / (x[end] - x[start]);
    }
}

double compute_derivative(double x[], double f[], int n, double target_x)
{
    double derivative = 0.0;
    for (int i = 0; i < n; i++)
    {
        double term = divided_difference(x, f, n, 0, i);
        for (int j = 0; j < i; j++)
        {
            term *= (target_x - x[j]);
        }
        derivative += term;
    }
    return derivative;
}

int main()
{
    int n;
    printf("Enter the number of points:");
    scanf("%d", &n); // Number of data points
    double x[n];     // x values

    double f[n]; // Corresponding f(x) values

    for (int i = 0; i < n; i++)
    {
        printf("Enter x and fx respectively:");
        scanf("%lf %lf", &x[i], &f[i]);
    }

    double target_x; // Point at which to compute the derivative
    double derivative = compute_derivative(x, f, n, target_x);
    printf("Enter the point at which the derivative is to be found out:");
    scanf("%lf", &target_x);
    printf("Derivative at x = %.2f is: %f\n", target_x, derivative);

    return 0;
}
