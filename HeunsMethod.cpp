#include <stdio.h>

#include <math.h>
#define f(x, y) 2 * (x) + (y)
int main()
{
	float x, xp, x0, y0, y, h, m1, m2;
	printf("Enter initial values of x and y :\n");
	scanf("%f%f", &x0, &y0);
	printf("Enter x at which function to be evaluated:\n");
	scanf("%f", &xp);
	printf("Enter the stepsize:\n");
	scanf("%f", &h);
	y = y0;
	x = x0;
	for (x = x0; x < xp; x = x + h)
	{
		m1 = f(x, y);
		m2 = f(x + h, y + h * m1);
		y = y + h / 2 * (m1 + m2);
	}
	printf("Function Value of x at %.3f =%.3f\n", xp, y);

	return 0;
}
