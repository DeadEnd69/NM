#include <stdio.h>
#include <math.h>

// Function to be integrated along the line
double line_integrand(double x)
{
    return x * x;
}

// Function to be integrated over a rectangular region
double double_integrand(double x, double y)
{
    return x * y;
}

double trapezoidal_line_integral(double (*f)(double), double a, double b, int n)
{
    double h = (b - a) / n;
    double integral = 0.5 * (f(a) + f(b));

    for (int i = 1; i < n; i++)
    {
        double x = a + i * h;
        integral += f(x);
    }

    integral *= h;
    return integral;
}

double trapezoidal_double_integral(double (*f)(double, double), double a, double b, double c, double d, int nx, int ny)
{
    double hx = (b - a) / nx;
    double hy = (d - c) / ny;
    double integral = 0.0;

    for (int i = 0; i <= nx; i++)
    {
        for (int j = 0; j <= ny; j++)
        {
            double x = a + i * hx;
            double y = c + j * hy;

            double term = f(x, y);

            if (i == 0 || i == nx)
            {
                term *= 0.5;
            }
            if (j == 0 || j == ny)
            {
                term *= 0.5;
            }

            integral += term;
        }
    }

    integral *= hx * hy;
    return integral;
}

int main()
{
    double a_line = 0.0;
    double b_line = 2.0;
    int n_line = 100;

    double a_double = 0.0;
    double b_double = 1.0;
    double c_double = 0.0;
    double d_double = 2.0;
    int nx_double = 100;
    int ny_double = 100;

    double line_integral = trapezoidal_line_integral(line_integrand, a_line, b_line, n_line);
    double double_integral = trapezoidal_double_integral(double_integrand, a_double, b_double, c_double, d_double, nx_double, ny_double);

    printf("Line Integral: %f\n", line_integral);
    printf("Double Integral: %f\n", double_integral);

    return 0;
}
